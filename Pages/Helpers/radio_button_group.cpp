#include <iostream>
#include "radio_button_group.h"

RadioButtonGroup::RadioButtonGroup() :
    layout_(new QGridLayout) {
  for (int i = 0; i < 3; ++i) {
    answers_.push_back(new QRadioButton(this));
  }

  layout_->addWidget(answers_[0], 0, 0, 1, 1, Qt::AlignLeft);
  layout_->addWidget(answers_[1], 1, 0, 1, 1, Qt::AlignLeft);
  layout_->addWidget(answers_[2], 2, 0, 1, 1, Qt::AlignLeft);
  setLayout(layout_);
}

void RadioButtonGroup::Reset() {
  for (int i = 0; i < 3; ++i) {
    answers_[i]->setCheckable(false);
    answers_[i]->setCheckable(true);
  }
  chosen_answer_ = "";
}

void RadioButtonGroup::SetAnswers(const std::vector<QString>& answers) {
  for (int i = 0; i < 3; ++i) {
    answers_[i]->setText(answers[i]);
  }
}

const std::string& RadioButtonGroup::GetChosenAnswer() const {
  return chosen_answer_;
}

void RadioButtonGroup::SetStyle() {
  QFont font;
  font.setPixelSize(16);
  for (auto& answer: answers_) {
    answer->setFont(font);
  }
}

void RadioButtonGroup::ConnectButtons() {
  connect(answers_[0], &QRadioButton::pressed, this, [&] {
    chosen_answer_ = answers_[0]->text().toStdString();
  });
  connect(answers_[1], &QRadioButton::pressed, this, [&] {
    chosen_answer_ = answers_[1]->text().toStdString();
  });
  connect(answers_[2], &QRadioButton::pressed, this, [&] {
    chosen_answer_ = answers_[2]->text().toStdString();
  });
}
