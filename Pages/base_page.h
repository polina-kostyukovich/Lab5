#ifndef BASE_PAGE_H_
#define BASE_PAGE_H_

#include <QGridLayout>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QWidget>

#include "Helpers/animation_widget.h"
#include "../View/abstract_view.h"

class BasePage : public QWidget {
 public:
  explicit BasePage(AbstractView* view);

  QWidget* GetCentralWidget() const;

  void ManageBaseLayout();
  void ConnectBaseWidgets();
  void SetBaseWidgetsStyle();

  virtual void ManageLayout() = 0;
  virtual void ConnectWidgets() = 0;
  virtual void SetWidgetsStyle() = 0;

  virtual const std::string& GetAnswer() const = 0;

  void SetMaxInProgress(int max_progress);

  void RewriteAttempts(int attempts);
  void ShowRightAnswer(const std::string& answer);

  void SetProgress(int progress);

  void ShowHappyEnd();
  void ShowUnhappyEnd();

 protected:
  AbstractView* view_;

  QWidget* central_widget_;
  QGridLayout* layout_;
  QLabel* progress_text_;
  QProgressBar* progress_;
  QLabel* task_;
  QLabel* right_answer_;
  QPushButton* to_main_;
  QLabel* attempts_left_;
  QPushButton* done_;
  QPushButton* next_;
  AnimationWidget image_;
};

#endif  // BASE_PAGE_H_
