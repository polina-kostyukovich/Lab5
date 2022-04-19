#ifndef ABSTRACT_VIEW_H
#define ABSTRACT_VIEW_H

#include <QMainWindow>

class AbstractView : public QMainWindow {
  Q_OBJECT
 public:
  virtual void Start() = 0;
  virtual void RewriteScore() = 0;

  virtual void SetMainPage() = 0;
  virtual void SetPickAnOptionPage() = 0;

 public slots:
  // main page
  virtual void RedirectPickAnOptionPressed() = 0;
  virtual void RedirectInputAnswerPressed() = 0;
  virtual void RedirectAudioPressed() = 0;
  virtual void RedirectMixedPressed() = 0;

  virtual void RedirectResetScore() = 0;

  virtual void RedirectSetSound(bool sound_on) = 0;
  virtual void RedirectSetSimpleTasks(bool simple_tasks) = 0;

  // base page
  virtual void RedirectToMainPressed() = 0;
  virtual void RedirectDonePressed() = 0;
};

#endif //ABSTRACT_VIEW_H
