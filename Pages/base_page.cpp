#include "base_page.h"

BasePage::BasePage(AbstractView* view) :
    view_(view),
    central_widget_(new QWidget(this)),
    layout_(new QGridLayout),
    progress_text_(new QLabel("Your progress in the exercise:",
                              central_widget_)),
    progress_(new QProgressBar(central_widget_)),
    task_(new QLabel(central_widget_)),
    right_answer_(new QLabel("", central_widget_)),
    to_main_(new QPushButton("To main page", central_widget_)),
    attempts_left_(new QLabel(central_widget_)),
    done_(new QPushButton("Done", central_widget_)),
    next_(new QPushButton("Next question", central_widget_)) {
  progress_->setAlignment(Qt::AlignCenter);
  progress_->setTextVisible(false);
  next_->setVisible(false);

  image_.Hide();
}

QWidget* BasePage::GetCentralWidget() const {
  return central_widget_;
}

void BasePage::ManageBaseLayout() {
  layout_->addWidget(progress_text_, 0, 0, 1, 2, Qt::AlignRight);
  layout_->addWidget(progress_, 0, 2, 1, 2, Qt::AlignLeft);
  layout_->addWidget(task_, 1, 1, 1, 2, Qt::AlignCenter);
  layout_->addWidget(right_answer_, 4, 1, 1, 2, Qt::AlignCenter);
  layout_->addWidget(to_main_, 5, 0, 1, 1, Qt::AlignCenter);
  layout_->addWidget(attempts_left_, 5, 1, 1, 2, Qt::AlignCenter);
  layout_->addWidget(done_, 5, 3, 1, 1, Qt::AlignCenter);
  layout_->addWidget(next_, 5, 3, 1, 1, Qt::AlignCenter);
  central_widget_->setLayout(layout_);
}

void BasePage::ConnectBaseWidgets() {
  connect(to_main_, &QPushButton::pressed, this, [&] {
    done_->setVisible(true);
    next_->setVisible(false);
    right_answer_->setText("");
    image_.Hide();
    view_->RedirectToMainPressed();
  });

  connect(done_, &QPushButton::pressed, this, [&] {
    done_->setVisible(false);
    next_->setVisible(true);
    right_answer_->setText("You are right!");
    view_->RedirectDonePressed();
  });

  connect(next_, &QPushButton::pressed, this, [&] {
    done_->setVisible(true);
    next_->setVisible(false);
    right_answer_->setText("");
    view_->RedirectNextPressed();
  });
}

void BasePage::SetBaseWidgetsStyle() {
  to_main_->setMinimumSize(170, 40);
  done_->setMinimumSize(170, 40);
  next_->setMinimumSize(170, 40);

  QFont font;
  font.setPixelSize(18);
  to_main_->setFont(font);
  done_->setFont(font);
  next_->setFont(font);
  progress_text_->setFont(font);

  font.setItalic(true);
  attempts_left_->setFont(font);
  task_->setFont(font);

  font.setPixelSize(20);
  right_answer_->setFont(font);
}

void BasePage::SetMaxInProgress(int max_progress) {
  progress_->setMaximum(max_progress);
}

void BasePage::RewriteAttempts(int attempts) {
  attempts_left_->setText("Left attempts: " + QString::number(attempts));
}

void BasePage::ShowRightAnswer(const std::string& answer) {
  right_answer_->setVisible(true);
  right_answer_->setText("Right answer: " + QString::fromStdString(answer));
}

void BasePage::SetProgress(int progress) {
  progress_->setValue(progress);
}

void BasePage::ShowHappyEnd() {
  done_->setVisible(false);
  next_->setVisible(false);

  image_.SetSize(view_->GetWindowWidth(), view_->GetWindowHeight());
  image_.ShowHappy();
  image_.setVisible(true);
}

void BasePage::ShowUnhappyEnd() {
  done_->setVisible(false);
  next_->setVisible(false);

  image_.SetSize(view_->GetWindowWidth(), view_->GetWindowHeight());
  image_.ShowUnhappy();
  image_.setVisible(true);
}
