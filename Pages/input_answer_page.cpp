#include "input_answer_page.h"

InputAnswerPage::InputAnswerPage(AbstractView* view) :
    BasePage(view),
    question_(new QLabel(this)),
    answer_(new QTextEdit(this)) {
  task_->setText("Put the verbs in brackets into the correct tense.");
}

void InputAnswerPage::ManageLayout() {
  BasePage::ManageBaseLayout();

  layout_->addWidget(question_, 2, 1, 1, 2, Qt::AlignCenter);
  layout_->addWidget(answer_, 3, 1, 1, 2, Qt::AlignCenter);
}

void InputAnswerPage::ConnectWidgets() {
  BasePage::ConnectBaseWidgets();

  connect(answer_, &QTextEdit::textChanged, this, [&]{
    string_answer_ = answer_->toPlainText().toStdString();
  });
}

void InputAnswerPage::SetWidgetsStyle() {
  BasePage::SetBaseWidgetsStyle();

  question_->setWordWrap(true);
  QFont font;
  font.setPixelSize(20);
  question_->setFont(font);
  font.setPixelSize(18);
  answer_->setFont(font);
}

const std::string& InputAnswerPage::GetAnswer() const {
  return string_answer_;
}

void InputAnswerPage::SetQuestion(const std::string& question) {
  question_->setText(QString::fromStdString(question));
}

void InputAnswerPage::ClearAnswer() {
  answer_->clear();
}
