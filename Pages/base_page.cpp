#include "base_page.h"

BasePage::BasePage(AbstractView* view) :
    view_(view),
    central_widget_(new QWidget(this)),
    layout_(new QGridLayout),
    progress_(new QProgressBar(central_widget_)),
    to_main_(new QPushButton("To main page", central_widget_)),
    attempts_left_(new QLabel(central_widget_)),
    done_(new QPushButton("Done", central_widget_)) {}

QWidget* BasePage::GetCentralWidget() const {
  return central_widget_;
}

void BasePage::ManageLayout() {
  layout_->addWidget(progress_, 0, 0, 1, 4, Qt::AlignCenter);
  layout_->addWidget(to_main_, 3, 0, 1, 1, Qt::AlignCenter);
  layout_->addWidget(attempts_left_, 3, 1, 1, 2, Qt::AlignCenter);
  layout_->addWidget(done_, 3, 3, 1, 1, Qt::AlignCenter);
  central_widget_->setLayout(layout_);
}

void BasePage::ConnectWidgets() {
  connect(to_main_,
          &QPushButton::pressed,
          view_,
          &AbstractView::RedirectToMainPressed);

  connect(done_,
          &QPushButton::pressed,
          view_,
          &AbstractView::RedirectDonePressed);
}

void BasePage::SetWidgetsStyle() {
  to_main_->setMinimumSize(170, 40);
  done_->setMinimumSize(170, 40);

  QFont font;
  font.setPixelSize(18);
  to_main_->setFont(font);
  done_->setFont(font);

  font.setItalic(true);
  attempts_left_->setFont(font);
}
