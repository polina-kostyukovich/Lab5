#ifndef SCORE_WIDGET_H_
#define SCORE_WIDGET_H_

#include <QContextMenuEvent>
#include <QGridLayout>
#include <QLabel>
#include <QMenu>
#include <QWidget>

#include "../../View/abstract_view.h"

class ScoreWidget : public QWidget {
 public:
  explicit ScoreWidget(AbstractView* view);

  void contextMenuEvent(QContextMenuEvent* event) override;

  void SetText(const QString& text);
  void SetFont(const QFont& font);

 private:
  QGridLayout* wrapper_;
  QLabel* score_text_;
  QMenu* context_menu_;
};

#endif  // SCORE_WIDGET_H_
