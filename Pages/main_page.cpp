#include "main_page.h"

#include <QMenuBar>

MainPage::MainPage(AbstractView* view) :
    view_(view),
    central_widget_(new QWidget(this)),
    main_page_layout_(new QGridLayout()),
    score_(view),
    mode_(new QLabel("Choose mode:", central_widget_)),
    pick_an_option_(new QPushButton("Pick an option", central_widget_)),
    input_answer_(new QPushButton("Input answer", central_widget_)),
    audio_(new QPushButton("Audio", central_widget_)),
    mixed_(new QPushButton("Mixed", central_widget_)),
    exit_(new QPushButton("Exit", central_widget_)) {}

QWidget* MainPage::GetCentralWidget() const {
  return central_widget_;
}

void MainPage::ManageLayout() {
  main_page_layout_->addWidget(&score_, 1, 1, 1, 2, Qt::AlignCenter);
  main_page_layout_->addWidget(mode_, 2, 1, 1, 2, Qt::AlignHCenter);
  main_page_layout_->addWidget(pick_an_option_, 3, 0, 1, 1, Qt::AlignCenter);
  main_page_layout_->addWidget(input_answer_, 3, 1, 1, 1, Qt::AlignCenter);
  main_page_layout_->addWidget(audio_, 3, 2, 1, 1, Qt::AlignCenter);
  main_page_layout_->addWidget(mixed_, 3, 3, 1, 1, Qt::AlignCenter);
  main_page_layout_->addWidget(exit_, 4, 3, 1, 1, Qt::AlignRight);
  central_widget_->setLayout(main_page_layout_);
}

void MainPage::ConnectWidgets() {
  connect(pick_an_option_,
          &QPushButton::pressed,
          view_,
          &AbstractView::RedirectPickAnOptionPressed);

  connect(input_answer_,
          &QPushButton::pressed,
          view_,
          &AbstractView::RedirectInputAnswerPressed);

  connect(audio_,
          &QPushButton::pressed,
          view_,
          &AbstractView::RedirectAudioPressed);

  connect(mixed_,
          &QPushButton::pressed,
          view_,
          &AbstractView::RedirectMixedPressed);

  connect(exit_, &QPushButton::pressed, view_, &QMainWindow::close);
}

void MainPage::SetWidgetsStyle() {
  score_.setMinimumSize(300, 50);

  pick_an_option_->setMinimumSize(170, 40);
  input_answer_->setMinimumSize(170, 40);
  audio_->setMinimumSize(170, 40);
  mixed_->setMinimumSize(170, 40);
  exit_->setMinimumSize(120, 35);

  QFont font;
  font.setPixelSize(18);
  pick_an_option_->setFont(font);
  input_answer_->setFont(font);
  audio_->setFont(font);
  mixed_->setFont(font);

  font.setPixelSize(16);
  exit_->setFont(font);

  font.setPixelSize(24);
  score_.SetFont(font);
  mode_->setFont(font);
}

void MainPage::CreateMenu(bool sound_on) {
  auto menu = view_->menuBar()->addMenu("...");

  auto complexity_menu = menu->addMenu("Choose complexity");
  auto simple_action = complexity_menu->addAction("Simple");
  auto difficult_action = complexity_menu->addAction("Difficult");
  connect(simple_action, &QAction::triggered, this, [&, simple_action]{
    view_->RedirectSetSimpleTasks(true);
  });
  connect(difficult_action, &QAction::triggered, this, [&, difficult_action]{
    view_->RedirectSetSimpleTasks(false);
  });

  auto sound_action = menu->addAction("Sound on");
  sound_action->setCheckable(true);
  sound_action->setChecked(sound_on);
  connect(sound_action, &QAction::triggered, this, [&, sound_action]{
    view_->RedirectSetSound(sound_action->isChecked());
  });

  auto reset_action = menu->addAction("Reset score");
  connect(reset_action, &QAction::triggered, view_, &AbstractView::RedirectResetScore);
}

void MainPage::RewriteScore(int new_score) {
  score_.SetText("Your score is: " + QString::number(new_score));
}
