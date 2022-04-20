#include "model.h"

#include <random>

int Model::GetScore() const {
  return score_;
}

void Model::SetScore(int score) {
  score_ = score;
}

void Model::SetPickAnOptionSimpleQuestions(
    std::vector<ManyAnswersQuestion>&& questions) {
  pick_an_option_simple_questions_ = std::move(questions);
  std::shuffle(pick_an_option_simple_questions_.begin(),
               pick_an_option_simple_questions_.end(),
               std::mt19937(std::random_device()()));
}

void Model::SetPickAnOptionDifficultQuestions(
    std::vector<ManyAnswersQuestion>&& questions) {
  pick_an_option_difficult_questions_ = std::move(questions);
  std::shuffle(pick_an_option_difficult_questions_.begin(),
               pick_an_option_difficult_questions_.end(),
               std::mt19937(std::random_device()()));
}

const ManyAnswersQuestion& Model::GetNextPickAnOptionSimpleQuestion() {
  ++current_pick_an_option_simple_question_;
  return pick_an_option_simple_questions_[
      current_pick_an_option_simple_question_
          % pick_an_option_simple_questions_.size()];
}

const ManyAnswersQuestion& Model::GetCurrentPickAnOptionSimpleQuestion() const {
  return pick_an_option_simple_questions_[
      current_pick_an_option_simple_question_
          % pick_an_option_simple_questions_.size()];
}

const ManyAnswersQuestion& Model::GetNextPickAnOptionDifficultQuestion() {
  ++current_pick_an_option_difficult_question_;
  return pick_an_option_difficult_questions_[
      current_pick_an_option_difficult_question_
          % pick_an_option_difficult_questions_.size()];
}

const ManyAnswersQuestion& Model::GetCurrentPickAnOptionDifficultQuestion()
    const {
  return pick_an_option_difficult_questions_[
      current_pick_an_option_difficult_question_
          % pick_an_option_difficult_questions_.size()];
}

void Model::SetInputAnswerSimpleQuestions(
    std::vector<TextAnswerQuestion>&& questions) {
  input_answer_simple_questions_ = std::move(questions);
  std::shuffle(input_answer_simple_questions_.begin(),
               input_answer_simple_questions_.end(),
               std::mt19937(std::random_device()()));
}

void Model::SetInputAnswerDifficultQuestions(
    std::vector<TextAnswerQuestion>&& questions) {
  input_answer_difficult_questions_ = std::move(questions);
  std::shuffle(input_answer_difficult_questions_.begin(),
               input_answer_difficult_questions_.end(),
               std::mt19937(std::random_device()()));
}

const TextAnswerQuestion& Model::GetNextInputAnswerSimpleQuestion() {
  ++current_input_answer_simple_question_;
  return input_answer_simple_questions_[
      current_input_answer_simple_question_
          % input_answer_simple_questions_.size()];
}

const TextAnswerQuestion& Model::GetCurrentInputAnswerSimpleQuestion() const {
  return input_answer_simple_questions_[
      current_input_answer_simple_question_
          % input_answer_simple_questions_.size()];
}

const TextAnswerQuestion& Model::GetNextInputAnswerDifficultQuestion() {
  ++current_input_answer_difficult_question_;
  return input_answer_difficult_questions_[
      current_input_answer_difficult_question_
          % input_answer_difficult_questions_.size()];
}

const TextAnswerQuestion& Model::GetCurrentInputAnswerDifficultQuestion()
const {
  return input_answer_difficult_questions_[
      current_input_answer_difficult_question_
          % input_answer_difficult_questions_.size()];
}
