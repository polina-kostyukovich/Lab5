#include "score_widget.h"

ScoreWidget::ScoreWidget(AbstractView* view) :
    wrapper_(new QGridLayout()),
    score_text_(new QLabel(this)),
    context_menu_(new QMenu) {
  wrapper_->addWidget(score_text_, 0, 0, 1, 1, Qt::AlignCenter);
  setLayout(wrapper_);
  context_menu_->addAction("Reset score",
                           view,
                           &AbstractView::RedirectResetScore);
}

void ScoreWidget::SetText(const QString& text) {
  score_text_->setText(text);
}

void ScoreWidget::SetFont(const QFont& font) {
  score_text_->setFont(font);
}

void ScoreWidget::contextMenuEvent(QContextMenuEvent* event) {
  context_menu_->exec(event->globalPos());
}
