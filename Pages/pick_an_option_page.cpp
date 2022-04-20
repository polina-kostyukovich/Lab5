#include "pick_an_option_page.h"

#include <random>

PickAnOptionPage::PickAnOptionPage(AbstractView* view) :
    BasePage(view),
    question_(new QLabel(this)) {
  task_->setText("Choose the correct answer.");
}

void PickAnOptionPage::ManageLayout() {
  BasePage::ManageBaseLayout();

  layout_->addWidget(question_, 2, 1, 1, 2, Qt::AlignCenter);
  layout_->addWidget(&buttons_, 3, 1, 1, 2, Qt::AlignCenter);
}

void PickAnOptionPage::ConnectWidgets() {
  BasePage::ConnectBaseWidgets();
  buttons_.ConnectButtons();
}

void PickAnOptionPage::SetWidgetsStyle() {
  BasePage::SetBaseWidgetsStyle();
  buttons_.SetStyle();

  QFont font;
  font.setPixelSize(20);
  question_->setFont(font);
}

const std::string& PickAnOptionPage::GetAnswer() const {
  return buttons_.GetChosenAnswer();
}

void PickAnOptionPage::SetQuestion(const ManyAnswersQuestion& task) {
  question_->setText(QString::fromStdString(task.question));

  std::vector<QString> answers(3);
  answers[0] = QString::fromStdString(task.right_answer);
  answers[1] = QString::fromStdString(task.wrong_answer1);
  answers[2] = QString::fromStdString(task.wrong_answer2);
  std::shuffle(answers.begin(),
               answers.end(),
               std::mt19937(std::random_device()()));
  buttons_.Reset();
  buttons_.SetAnswers(answers);
}
