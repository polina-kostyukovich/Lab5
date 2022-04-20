#ifndef QUESTION_STRUCTS_H
#define QUESTION_STRUCTS_H

#include <string>

struct ManyAnswersQuestion {
  std::string question;
  std::string right_answer;
  std::string wrong_answer1;
  std::string wrong_answer2;
};

struct TextAnswerQuestion {
  std::string question;
  std::string answer;
};

#endif //QUESTION_STRUCTS_H
