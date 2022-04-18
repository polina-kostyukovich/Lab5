#include "view.h"

#include <QMessageBox>
#include <QMenuBar>

View::View(const std::shared_ptr<Controller>& controller) :
    controller_(controller) {
  main_page_ = std::make_unique<MainPage>(this);
  setMinimumSize(900, 600);
}

void View::Start() {
  ManageLayouts();
  ConnectWidgets();
  SetWidgetsStyle();

  setCentralWidget(main_page_->GetCentralWidget());
}

void View::ManageLayouts() {
  main_page_->ManageLayout();
}

void View::ConnectWidgets() {
  main_page_->ConnectWidgets();
  main_page_->CreateMenu(controller_->GetSoundOn());
}

void View::SetWidgetsStyle() {
  main_page_->SetWidgetsStyle();
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

void View::RewriteScore() {
  main_page_->RewriteScore(controller_->GetScore());
}
