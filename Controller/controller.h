#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <memory>
#include <QObject>
#include <QSettings>

#include "../Model/model.h"
#include "../Pages/Helpers/question_structs.h"
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

  void ReadData();
  void ReadDataForPickAnOption();
  void ReadDataForInputAnswer();

  int GetNumberOfTasksInExercise() const;
  int GetLeftAttempts() const;
  int GetScore() const;
  void ResetScore();

  bool GetSoundOn() const;
  void SetSound(bool sound_on);
  void SetSimpleTasks(bool simple_tasks);

  void HandlePickAnOptionPressed();
  void HandleInputAnswerPressed();
  void HandleAudioPressed();

  void HandleToMainPressed();

  void SetNextPickAnOptionQuestion();
  void HandleAnswerChosen(const std::string& answer);

  void SetNextInputAnswerQuestion();
  void HandleInputAnswerEntered(const std::string& answer);

 private:
  static std::shared_ptr<Controller> controller_;

  std::unique_ptr<Model> model_;
  std::unique_ptr<AbstractView> view_;

  bool sound_on_;
  bool simple_tasks_;

  const int kNumberOfTasksInExercise = 5;
  const int kNumberOfAttempts = 2;
  int current_score_{0};
  int attempts_left_{kNumberOfAttempts};
  int number_of_tasks_left_{kNumberOfTasksInExercise};
};

#endif  // CONTROLLER_H_
