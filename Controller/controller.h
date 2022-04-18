#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <memory>
#include <QObject>
#include <QSettings>

#include "../Model/model.h"
#include "../View/abstract_view.h"

class Controller : public QObject {
  Q_OBJECT
 private:
  Controller() = default;

 public:
  static std::shared_ptr<Controller> GetController();
  void Run();

  void SetView(std::unique_ptr<AbstractView>&& view);
  void SetModel(std::unique_ptr<Model>&& model);

  void ReadSettings();
  void WriteSettings();

  int GetScore() const;
  void ResetScore();

  bool GetSoundOn() const;
  void SetSound(bool sound_on);
  void SetSimpleTasks(bool simple_tasks);

  void HandlePickAnOptionPressed();
  void HandleInputAnswerPressed();
  void HandleAudioPressed();
  void HandleMixedPressed();

  void HandleToMainPressed();
  void HandleDonePressed();

 private:
  static std::shared_ptr<Controller> controller_;

  std::unique_ptr<Model> model_;
  std::unique_ptr<AbstractView> view_;

  bool sound_on_;
  bool simple_tasks_;
};

#endif  // CONTROLLER_H_
