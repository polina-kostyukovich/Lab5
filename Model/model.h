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

  // pick-an-option questions
  void SetPickAnOptionSimpleQuestions(
      std::vector<ManyAnswersQuestion>&& questions);
  void SetPickAnOptionDifficultQuestions(
      std::vector<ManyAnswersQuestion>&& questions);

  const ManyAnswersQuestion& GetNextPickAnOptionSimpleQuestion();
  const ManyAnswersQuestion& GetCurrentPickAnOptionSimpleQuestion() const;

  const ManyAnswersQuestion& GetNextPickAnOptionDifficultQuestion();
  const ManyAnswersQuestion& GetCurrentPickAnOptionDifficultQuestion() const;

  // input-answer questions
  void SetInputAnswerSimpleQuestions(
      std::vector<TextAnswerQuestion>&& questions);
  void SetInputAnswerDifficultQuestions(
      std::vector<TextAnswerQuestion>&& questions);

  const TextAnswerQuestion& GetNextInputAnswerSimpleQuestion();
  const TextAnswerQuestion& GetCurrentInputAnswerSimpleQuestion() const;

  const TextAnswerQuestion& GetNextInputAnswerDifficultQuestion();
  const TextAnswerQuestion& GetCurrentInputAnswerDifficultQuestion() const;

 private:
  int score_;

  std::vector<ManyAnswersQuestion> pick_an_option_simple_questions_;
  int current_pick_an_option_simple_question_{-1};
  std::vector<ManyAnswersQuestion> pick_an_option_difficult_questions_;
  int current_pick_an_option_difficult_question_{-1};

  std::vector<TextAnswerQuestion> input_answer_simple_questions_;
  int current_input_answer_simple_question_{-1};
  std::vector<TextAnswerQuestion> input_answer_difficult_questions_;
  int current_input_answer_difficult_question_{-1};
};

#endif  // MODEL_H_
