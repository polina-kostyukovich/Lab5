#include "view.h"

#include <QMessageBox>
#include <QMenuBar>

View::View(const std::shared_ptr<Controller>& controller) :
    controller_(controller) {
  main_page_ = std::make_unique<MainPage>(this);
  pick_an_option_page_ = std::make_unique<PickAnOptionPage>(this);
  input_answer_page_ = std::make_unique<InputAnswerPage>(this);
  setMinimumSize(900, 600);

  pick_an_option_page_->SetMaxInProgress(
      controller_->GetNumberOfTasksInExercise());
  input_answer_page_->SetMaxInProgress(
      controller_->GetNumberOfTasksInExercise());
}

void View::Start() {
  ManageLayouts();
  ConnectWidgets();
  SetWidgetsStyle();

  setCentralWidget(main_page_->GetCentralWidget());
}

int View::GetWindowWidth() const {
  return window_width_;
}

int View::GetWindowHeight() const {
  return window_height_;
}

void View::ManageLayouts() {
  main_page_->ManageLayout();
  pick_an_option_page_->ManageLayout();
  input_answer_page_->ManageLayout();
}

void View::ConnectWidgets() {
  main_page_->ConnectWidgets();
  main_page_->CreateMenu(controller_->GetSoundOn());
  pick_an_option_page_->ConnectWidgets();
  input_answer_page_->ConnectWidgets();
}

void View::SetWidgetsStyle() {
  main_page_->SetWidgetsStyle();
  pick_an_option_page_->SetWidgetsStyle();
  input_answer_page_->SetWidgetsStyle();
}

void View::RewriteScore() {
  main_page_->RewriteScore(controller_->GetScore());
}

void View::RewriteAttempts() {
  if (centralWidget() == pick_an_option_page_->GetCentralWidget()) {
    pick_an_option_page_->RewriteAttempts(controller_->GetLeftAttempts());
  }
  if (centralWidget() == input_answer_page_->GetCentralWidget()) {
    input_answer_page_->RewriteAttempts(controller_->GetLeftAttempts());
  }
}

void View::ShowRightAnswer(const std::string& answer) {
  if (centralWidget() == pick_an_option_page_->GetCentralWidget()) {
    pick_an_option_page_->ShowRightAnswer(answer);
  }
  if (centralWidget() == input_answer_page_->GetCentralWidget()) {
    input_answer_page_->ShowRightAnswer(answer);
  }
}

void View::SetMainPage() {
  takeCentralWidget();
  setCentralWidget(main_page_->GetCentralWidget());
}

void View::SetPickAnOptionPage() {
  takeCentralWidget();
  setCentralWidget(pick_an_option_page_->GetCentralWidget());
  RewriteAttempts();
}

void View::SetPickAnOptionQuestion(const ManyAnswersQuestion& task) {
  pick_an_option_page_->SetQuestion(task);
}

void View::SetInputAnswerPage() {
  takeCentralWidget();
  setCentralWidget(input_answer_page_->GetCentralWidget());
  RewriteAttempts();
  input_answer_page_->ClearAnswer();
}

void View::SetInputAnswerQuestion(const std::string& question) {
  input_answer_page_->SetQuestion(question);
}

void View::ShowExerciseHappyEnd() {
  if (centralWidget() == pick_an_option_page_->GetCentralWidget()) {
    pick_an_option_page_->ShowHappyEnd();
  }
  if (centralWidget() == input_answer_page_->GetCentralWidget()) {
    input_answer_page_->ShowHappyEnd();
  }
}

void View::ShowExerciseUnhappyEnd() {
  if (centralWidget() == pick_an_option_page_->GetCentralWidget()) {
    pick_an_option_page_->ShowUnhappyEnd();
  }
  if (centralWidget() == input_answer_page_->GetCentralWidget()) {
    input_answer_page_->ShowUnhappyEnd();
  }
}

void View::closeEvent(QCloseEvent* event) {
  auto answer = QMessageBox::question(this, "Exit?",
                                      "Do you really want to exit?");
  if (answer == QMessageBox::Yes) {
    controller_->WriteSettings();
    close();
  } else {
    event->ignore();
  }
}

void View::resizeEvent(QResizeEvent* event) {
  window_width_ = event->size().width();
  window_height_ = event->size().height();
}

void View::RedirectPickAnOptionPressed() {
  controller_->HandlePickAnOptionPressed();
}

void View::RedirectInputAnswerPressed() {
  controller_->HandleInputAnswerPressed();
}

void View::RedirectAudioPressed() {
  controller_->HandleAudioPressed();
}

void View::RedirectMixedPressed() {
  controller_->HandleMixedPressed();
}

void View::RedirectResetScore() {
  controller_->ResetScore();
}

void View::RedirectSetSound(bool sound_on) {
  controller_->SetSound(sound_on);
}

void View::RedirectSetSimpleTasks(bool simple_tasks) {
  controller_->SetSimpleTasks(simple_tasks);
}

void View::RedirectToMainPressed() {
  controller_->HandleToMainPressed();
}

void View::RedirectDonePressed() {
  if (centralWidget() == pick_an_option_page_->GetCentralWidget()) {
    controller_->HandleAnswerChosen(pick_an_option_page_->GetAnswer());
  }
  if (centralWidget() == input_answer_page_->GetCentralWidget()) {
    controller_->HandleInputAnswerEntered(input_answer_page_->GetAnswer());
  }
}

void View::RedirectNextPressed() {
  if (centralWidget() == pick_an_option_page_->GetCentralWidget()) {
    controller_->SetNextPickAnOptionQuestion();
  }
  if (centralWidget() == input_answer_page_->GetCentralWidget()) {
    controller_->SetNextInputAnswerQuestion();
    input_answer_page_->ClearAnswer();
  }
}
