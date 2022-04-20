#ifndef ABSTRACT_VIEW_H
#define ABSTRACT_VIEW_H

#include <QMainWindow>

#include "../Pages/Helpers/question_structs.h"

class AbstractView : public QMainWindow {
  Q_OBJECT
 public:
  virtual void Start() = 0;

  virtual int GetWindowWidth() const = 0;
  virtual int GetWindowHeight() const = 0;

  virtual void RewriteScore() = 0;
  virtual void RewriteAttempts() = 0;
  virtual void ShowRightAnswer(const std::string& answer) = 0;

  virtual void SetProgress(int progress) = 0;

  virtual void SetMainPage() = 0;

  virtual void SetPickAnOptionPage() = 0;
  virtual void SetPickAnOptionQuestion(const ManyAnswersQuestion&) = 0;

  virtual void SetInputAnswerPage() = 0;
  virtual void SetInputAnswerQuestion(const std::string& question) = 0;

  virtual void ShowExerciseHappyEnd() = 0;
  virtual void ShowExerciseUnhappyEnd() = 0;

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
  virtual void RedirectNextPressed() = 0;
};

#endif //ABSTRACT_VIEW_H
