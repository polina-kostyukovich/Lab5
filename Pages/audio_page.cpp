#include "audio_page.h"

AudioPage::AudioPage(AbstractView* view) :
    BasePage(view),
    play_(new QPushButton("Play!", this)),
    stop_(new QPushButton("Stop", this)),
    answer_(new QTextEdit(this)) {
  task_->setText("Type what you hear");
  stop_->setVisible(false);
}

void AudioPage::ManageLayout() {
  BasePage::ManageBaseLayout();

  layout_->addWidget(play_, 2, 1, 1, 2, Qt::AlignCenter);
  layout_->addWidget(stop_, 2, 1, 1, 2, Qt::AlignCenter);
  layout_->addWidget(answer_, 3, 1, 1, 2, Qt::AlignCenter);
}

void AudioPage::ConnectWidgets() {
  BasePage::ConnectBaseWidgets();

  connect(play_, &QPushButton::pressed, this, [&]{
    play_->setVisible(false);
    stop_->setVisible(true);

  });
  connect(stop_, &QPushButton::pressed, this, [&]{
    play_->setVisible(true);
    stop_->setVisible(false);

  });

  connect(answer_, &QTextEdit::textChanged, this, [&]{
    string_answer_ = answer_->toPlainText().toStdString();
  });
}

void AudioPage::SetWidgetsStyle() {
  BasePage::SetBaseWidgetsStyle();

  QFont font;
  font.setPixelSize(18);
  answer_->setFont(font);
}

const std::string& AudioPage::GetAnswer() const {
  return string_answer_;
}

void AudioPage::ClearAnswer() {
  answer_->clear();
}
