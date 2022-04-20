#include "controller.h"

#include <fstream>

std::shared_ptr<Controller> Controller::controller_ = nullptr;

std::shared_ptr<Controller> Controller::GetController() {
  if (controller_ == nullptr) {
    auto controller = new Controller;
    controller_ = std::shared_ptr<Controller>(controller);
  }
  return controller_;
}

void Controller::Run() {
  ReadSettings();
  ReadData();
  view_->Start();
  view_->RewriteScore();
  view_->show();
}

void Controller::SetView(std::unique_ptr<AbstractView>&& view) {
  view_ = std::move(view);
}

void Controller::SetModel(std::unique_ptr<Model>&& model) {
  model_ = std::move(model);
}

void Controller::ReadSettings() {
  QSettings settings("Polina Kostyukovich", "Lab5");
  model_->SetScore(settings.value("Score").toInt());
  sound_on_ = settings.value("SoundOn").toBool();
  simple_tasks_ = settings.value("SimpleTasks").toBool();
}

void Controller::WriteSettings() {
  QSettings settings("Polina Kostyukovich", "Lab5");
  settings.setValue("Score", model_->GetScore());
  settings.setValue("SoundOn", sound_on_);
  settings.setValue("SimpleTasks", simple_tasks_);
}

void Controller::ReadData() {
  ReadDataForPickAnOption();
  ReadDataForInputAnswer();
}

void Controller::ReadDataForPickAnOption() {
  std::ifstream
      read_simple("../Pages/Exercises/pick_an_option_exercises_simple.txt");
  int number_of_tasks;
  read_simple >> number_of_tasks;
  read_simple.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::vector<ManyAnswersQuestion> simple_tasks(number_of_tasks);
  for (auto& task: simple_tasks) {
    std::getline(read_simple, task.question);
    std::getline(read_simple, task.right_answer);
    std::getline(read_simple, task.wrong_answer1);
    std::getline(read_simple, task.wrong_answer2);
  }
  model_->SetPickAnOptionSimpleQuestions(std::move(simple_tasks));

  std::ifstream read_difficult
      ("../Pages/Exercises/pick_an_option_exercises_difficult.txt");
  read_difficult >> number_of_tasks;
  read_difficult.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::vector<ManyAnswersQuestion> difficult_tasks(number_of_tasks);
  for (auto& task: difficult_tasks) {
    std::getline(read_difficult, task.question);
    std::getline(read_difficult, task.right_answer);
    std::getline(read_difficult, task.wrong_answer1);
    std::getline(read_difficult, task.wrong_answer2);
  }
  model_->SetPickAnOptionDifficultQuestions(std::move(difficult_tasks));
}

void Controller::ReadDataForInputAnswer() {
  std::ifstream
      read_simple("../Pages/Exercises/input_answer_exercises_simple.txt");
  int number_of_tasks;
  read_simple >> number_of_tasks;
  read_simple.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::vector<TextAnswerQuestion> simple_tasks(number_of_tasks);
  for (auto& task: simple_tasks) {
    std::getline(read_simple, task.question);
    std::getline(read_simple, task.answer);
  }
  model_->SetInputAnswerSimpleQuestions(std::move(simple_tasks));

  std::ifstream
      read_difficult("../Pages/Exercises/input_answer_exercises_difficult.txt");
  read_difficult >> number_of_tasks;
  read_difficult.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::vector<TextAnswerQuestion> difficult_tasks(number_of_tasks);
  for (auto& task: difficult_tasks) {
    std::getline(read_difficult, task.question);
    std::getline(read_difficult, task.answer);
  }
  model_->SetInputAnswerDifficultQuestions(std::move(difficult_tasks));
}

int Controller::GetNumberOfTasksInExercise() const {
  return kNumberOfTasksInExercise;
}

int Controller::GetLeftAttempts() const {
  return attempts_left_;
}

int Controller::GetScore() const {
  return model_->GetScore();
}

void Controller::ResetScore() {
  model_->SetScore(0);
  view_->RewriteScore();
}

bool Controller::GetSoundOn() const {
  return sound_on_;
}

void Controller::SetSound(bool sound_on) {
  sound_on_ = sound_on;
}

void Controller::SetSimpleTasks(bool simple_tasks) {
  simple_tasks_ = simple_tasks;
}

void Controller::HandlePickAnOptionPressed() {
  view_->SetPickAnOptionPage();
  SetNextPickAnOptionQuestion();
}

void Controller::HandleInputAnswerPressed() {
  view_->SetInputAnswerPage();
  SetNextInputAnswerQuestion();
}

void Controller::HandleAudioPressed() {
  view_->SetAudioPage();
  SetNextAudioQuestion();
}

void Controller::HandleMixedPressed() {

}

void Controller::HandleToMainPressed() {
  current_score_ = 0;
  number_of_tasks_left_ = kNumberOfTasksInExercise;
  attempts_left_ = kNumberOfAttempts;
  view_->SetMainPage();
}

void Controller::SetNextPickAnOptionQuestion() {
  if (simple_tasks_) {
    view_->SetPickAnOptionQuestion(
        model_->GetNextPickAnOptionSimpleQuestion());
  } else {
    view_->SetPickAnOptionQuestion(
        model_->GetNextPickAnOptionDifficultQuestion());
  }
}

void Controller::HandleAnswerChosen(const std::string& answer) {
  if (simple_tasks_) {
    if (answer == model_->GetCurrentPickAnOptionSimpleQuestion().right_answer) {
      current_score_ += 10;
      // todo happy sound
    } else {
      // todo upset sound
      --attempts_left_;
      view_->ShowRightAnswer(
          model_->GetCurrentPickAnOptionSimpleQuestion().right_answer);
      if (attempts_left_ == -1) {
        view_->ShowExerciseUnhappyEnd();
        return;
      }
      view_->RewriteAttempts();
    }
  } else {
    if (answer
        == model_->GetCurrentPickAnOptionDifficultQuestion().right_answer) {
      current_score_ += 20;

      // todo happy sound
    } else {
      // todo upset sound

      --attempts_left_;
      view_->ShowRightAnswer(
          model_->GetCurrentPickAnOptionDifficultQuestion().right_answer);
      if (attempts_left_ == -1) {
        view_->ShowExerciseUnhappyEnd();
        return;
      }
      view_->RewriteAttempts();
    }
  }
  --number_of_tasks_left_;
  if (number_of_tasks_left_ == 0) {
    model_->SetScore(model_->GetScore() + current_score_);
    view_->RewriteScore();
    view_->ShowExerciseHappyEnd();
  }
}

void Controller::SetNextInputAnswerQuestion() {
  if (simple_tasks_) {
    view_->SetInputAnswerQuestion(
        model_->GetNextInputAnswerSimpleQuestion().question);
  } else {
    view_->SetInputAnswerQuestion(
        model_->GetNextInputAnswerDifficultQuestion().question);
  }
}

void Controller::HandleInputAnswerEntered(const std::string& answer) {
  if (simple_tasks_) {
    if (answer == model_->GetCurrentInputAnswerSimpleQuestion().answer) {
      current_score_ += 10;
      // todo happy sound
    } else {
      // todo upset sound
      --attempts_left_;
      view_->ShowRightAnswer(
          model_->GetCurrentInputAnswerSimpleQuestion().answer);
      if (attempts_left_ == -1) {
        view_->ShowExerciseUnhappyEnd();
        return;
      }
      view_->RewriteAttempts();
    }
  } else {
    if (answer == model_->GetCurrentInputAnswerDifficultQuestion().answer) {
      current_score_ += 20;

      // todo happy sound
    } else {
      // todo upset sound

      --attempts_left_;
      view_->ShowRightAnswer(
          model_->GetCurrentInputAnswerDifficultQuestion().answer);
      if (attempts_left_ == -1) {
        view_->ShowExerciseUnhappyEnd();
        return;
      }
      view_->RewriteAttempts();
    }
  }
  --number_of_tasks_left_;
  if (number_of_tasks_left_ == 0) {
    model_->SetScore(model_->GetScore() + current_score_);
    view_->RewriteScore();
    view_->ShowExerciseHappyEnd();
  }
}

void Controller::SetNextAudioQuestion() {

}

const std::string& Controller::GetCurrentAudio() const {
  return "";
}
