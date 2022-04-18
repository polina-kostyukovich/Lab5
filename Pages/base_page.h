#ifndef BASE_PAGE_H_
#define BASE_PAGE_H_

#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QWidget>

#include "../View/abstract_view.h"

class BasePage : public QWidget {
 public:
  explicit BasePage(AbstractView* view);

  QWidget* GetCentralWidget() const;

  void ManageLayout();
  void ConnectWidgets();
  void SetWidgetsStyle();

 protected:
  AbstractView* view_;

  QWidget* central_widget_;
  QGridLayout* layout_;
  QProgressBar* progress_;
  QPushButton* to_main_;
  QLabel* attempts_left_;
  QPushButton* done_;
};

#endif  // BASE_PAGE_H_
