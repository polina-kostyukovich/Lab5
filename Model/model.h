#ifndef MODEL_H_
#define MODEL_H_

#include <memory>
#include <string>
#include <vector>

#include "../Pages/Helpers/question_structs.h"

class Model {
 public:
  Model() = default;

  int GetScore() const;
  void SetScore(int score);

  void SetPickAnOptionSimpleQuestions(
      std::vector<ManyAnswersQuestion>&& questions);
  void SetPickAnOptionDifficultQuestions(
      std::vector<ManyAnswersQuestion>&& questions);

  const ManyAnswersQuestion& GetNextPickAnOptionSimpleQuestion();
  const ManyAnswersQuestion& GetCurrentPickAnOptionSimpleQuestion() const;

  const ManyAnswersQuestion& GetNextPickAnOptionDifficultQuestion();
  const ManyAnswersQuestion& GetCurrentPickAnOptionDifficultQuestion() const;

 private:
  int score_;

  std::vector<ManyAnswersQuestion> pick_an_option_simple_questions_;
  int current_pick_an_option_simple_question_{-1};
  std::vector<ManyAnswersQuestion> pick_an_option_difficult_questions_;
  int current_pick_an_option_difficult_question_{-1};
};

#endif  // MODEL_H_
