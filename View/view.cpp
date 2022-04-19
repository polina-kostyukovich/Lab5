#include "view.h"

#include <QMessageBox>
#include <QMenuBar>

View::View(const std::shared_ptr<Controller>& controller) :
    controller_(controller) {
  main_page_ = std::make_unique<MainPage>(this);
  pick_an_option_page_ = std::make_unique<PickAnOptionPage>(this);
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
  pick_an_option_page_->ManageLayout();
}

void View::ConnectWidgets() {
  main_page_->ConnectWidgets();
  main_page_->CreateMenu(controller_->GetSoundOn());
  pick_an_option_page_->ConnectWidgets();
}

void View::SetWidgetsStyle() {
  main_page_->SetWidgetsStyle();
  pick_an_option_page_->SetWidgetsStyle();
}

void View::RewriteScore() {
  main_page_->RewriteScore(controller_->GetScore());
}

void View::SetMainPage() {
  takeCentralWidget();
  setCentralWidget(main_page_->GetCentralWidget());
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

void View::RedirectToMainPressed() {
  controller_->HandleToMainPressed();
}

void View::RedirectDonePressed() {
  if (centralWidget() == pick_an_option_page_->GetCentralWidget()) {
    controller_->HandleAnswerChosen(pick_an_option_page_->GetAnswer());
  }
}

void View::SetPickAnOptionPage() {
  takeCentralWidget();
  setCentralWidget(pick_an_option_page_->GetCentralWidget());
}
