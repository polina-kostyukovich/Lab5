#ifndef PICK_AN_OPTION_PAGE_H_
#define PICK_AN_OPTION_PAGE_H_

#include <string>
#include <QGroupBox>

#include "base_page.h"
#include "Helpers/question_structs.h"
#include "Helpers/radio_button_group.h"

class PickAnOptionPage : public BasePage {
 public:
  explicit PickAnOptionPage(AbstractView* view);

  void ManageLayout() override;
  void ConnectWidgets() override;
  void SetWidgetsStyle() override;

  const std::string& GetAnswer() const override;

  void SetQuestion(const ManyAnswersQuestion& task);

  void Reset();

 private:
  QLabel* question_;
  RadioButtonGroup buttons_;
};

#endif  // PICK_AN_OPTION_PAGE_H_
