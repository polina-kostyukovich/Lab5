#ifndef MAIN_PAGE_H_
#define MAIN_PAGE_H_

#include <QCloseEvent>
#include <QContextMenuEvent>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

#include "Helpers/score_widget.h"
#include "../View/abstract_view.h"

class MainPage : public QWidget {
 public:
  explicit MainPage(AbstractView* view);

  QWidget* GetCentralWidget() const;

  void ManageLayout();
  void ConnectWidgets();
  void SetWidgetsStyle();

  void CreateMenu(bool sound_on);

  void RewriteScore(int new_score);

 private:
  AbstractView* view_;

  QWidget* central_widget_;
  QGridLayout* main_page_layout_;
  ScoreWidget score_;
  QLabel* mode_;
  QPushButton* pick_an_option_;
  QPushButton* input_answer_;
  QPushButton* audio_;
  QPushButton* mixed_;
  QPushButton* exit_;
};

#endif  // MAIN_PAGE_H_
