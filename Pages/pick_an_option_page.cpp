#include "pick_an_option_page.h"

PickAnOptionPage::PickAnOptionPage(AbstractView* view) :
    BasePage(view),
    question_(new QLabel(this)) {}

void PickAnOptionPage::ManageLayout() {
  BasePage::ManageBaseLayout();

  layout_->addWidget(question_, 1, 1, 1, 2, Qt::AlignCenter);
  layout_->addWidget(&buttons_, 2, 1, 1, 2, Qt::AlignCenter);
}

void PickAnOptionPage::ConnectWidgets() {
  BasePage::ConnectBaseWidgets();
  buttons_.ConnectButtons();
}

void PickAnOptionPage::SetWidgetsStyle() {
  BasePage::SetBaseWidgetsStyle();
  buttons_.SetStyle();
}

int PickAnOptionPage::GetAnswer() const {
  return buttons_.GetChosenAnswer();
}
