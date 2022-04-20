#ifndef VIEW_H_
#define VIEW_H_

#include <memory>
#include <QCloseEvent>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>

#include "abstract_view.h"
#include "../Controller/controller.h"
#include "../Pages/main_page.h"
#include "../Pages/audio_page.h"
#include "../Pages/input_answer_page.h"
#include "../Pages/pick_an_option_page.h"

class View : public AbstractView {
 public:
  explicit View(const std::shared_ptr<Controller>& controller);

  void Start() override;

  int GetWindowWidth() const override;
  int GetWindowHeight() const override;

  void ManageLayouts();
  void ConnectWidgets();
  void SetWidgetsStyle();

  void RewriteScore() override;

  void RewriteAttempts() override;
  void ShowRightAnswer(const std::string& answer) override;

  void SetMainPage() override;

  void SetPickAnOptionPage() override;
  void SetPickAnOptionQuestion(const ManyAnswersQuestion& task) override;

  void SetInputAnswerPage() override;
  void SetInputAnswerQuestion(const std::string& question) override;

  void SetAudioPage() override;

  void ShowExerciseHappyEnd() override;
  void ShowExerciseUnhappyEnd() override;

  void closeEvent(QCloseEvent* event) override;
  void resizeEvent(QResizeEvent* event) override;

  void RedirectPickAnOptionPressed() override;
  void RedirectInputAnswerPressed() override;
  void RedirectAudioPressed() override;
  void RedirectMixedPressed() override;

  void RedirectResetScore() override;

  void RedirectSetSound(bool sound_on) override;
  void RedirectSetSimpleTasks(bool simple_tasks) override;

  void RedirectToMainPressed() override;
  void RedirectDonePressed() override;
  void RedirectNextPressed() override;

 private:
  std::shared_ptr<Controller> controller_;

  std::unique_ptr<MainPage> main_page_;
  std::unique_ptr<PickAnOptionPage> pick_an_option_page_;
  std::unique_ptr<InputAnswerPage> input_answer_page_;
  std::unique_ptr<AudioPage> audio_page_;

  int window_width_{900};
  int window_height_{600};
};

#endif  // VIEW_H_
