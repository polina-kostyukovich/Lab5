#include "controller.h"

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

int Controller::GetScore() const {
  return model_->GetScore();
}

void Controller::ResetScore() {
  model_->SetScore(0);
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
  // something with data
}

void Controller::HandleInputAnswerPressed() {

}

void Controller::HandleAudioPressed() {

}

void Controller::HandleMixedPressed() {

}

void Controller::HandleToMainPressed() {
  current_score_ = 0;
  view_->SetMainPage();
}

void Controller::HandleAnswerChosen(int answer) {
  // manipulations with data
}
