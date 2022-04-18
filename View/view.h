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

class View : public AbstractView {
 public:
  explicit View(const std::shared_ptr<Controller>& controller);
  void Start() override;

  void ManageLayouts();

  void ConnectWidgets();

  void SetWidgetsStyle();

  void closeEvent(QCloseEvent* event) override;

  void RedirectPickAnOptionPressed() override;
  void RedirectInputAnswerPressed() override;
  void RedirectAudioPressed() override;
  void RedirectMixedPressed() override;

  void RedirectResetScore() override;

  void RedirectSetSound(bool sound_on) override;
  void RedirectSetSimpleTasks(bool simple_tasks) override;

  void RewriteScore() override;

  void RedirectToMainPressed() override;
  void RedirectDonePressed() override;

 private:
  std::shared_ptr<Controller> controller_;

  std::unique_ptr<MainPage> main_page_;
};

#endif  // VIEW_H_
