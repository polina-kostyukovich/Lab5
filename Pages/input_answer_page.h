#ifndef INPUT_ANSWER_PAGE_H_
#define INPUT_ANSWER_PAGE_H_

#include <QTextEdit>

#include "base_page.h"
#include "Helpers/question_structs.h"

class InputAnswerPage : public BasePage {
 public:
  explicit InputAnswerPage(AbstractView* view);

  void ManageLayout() override;
  void ConnectWidgets() override;
  void SetWidgetsStyle() override;

  const std::string& GetAnswer() const override;

  void SetQuestion(const std::string& question);

  void ClearAnswer();

 private:
  QLabel* question_;
  QTextEdit* answer_;
  std::string string_answer_;
};

#endif  // INPUT_ANSWER_PAGE_H_
