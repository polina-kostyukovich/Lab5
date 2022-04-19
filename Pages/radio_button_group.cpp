#include "radio_button_group.h"

RadioButtonGroup::RadioButtonGroup() :
    layout_(new QGridLayout) {
  for (int i = 0; i < 3; ++i) {
    answers_.push_back(new QRadioButton(this));
  }

  answers_[0]->setText("First answer");
  answers_[1]->setText("Second answer");
  answers_[2]->setText("Third answer");

  layout_->addWidget(answers_[0], 0, 0, 1, 1, Qt::AlignLeft);
  layout_->addWidget(answers_[1], 1, 0, 1, 1, Qt::AlignLeft);
  layout_->addWidget(answers_[2], 2, 0, 1, 1, Qt::AlignLeft);
  setLayout(layout_);
}

int RadioButtonGroup::GetChosenAnswer() const {
  return chosen_answer_;
}

void RadioButtonGroup::SetStyle() {
  QFont font;
  font.setPixelSize(14);
  for (auto& answer : answers_) {
    answer->setFont(font);
  }
}

void RadioButtonGroup::ConnectButtons() {
  for (int i = 0; i < 3; ++i) {
    connect(answers_[i], &QRadioButton::pressed, this, [&]{
      chosen_answer_ = i;
    });
  }
}
