#ifndef RADIO_BUTTON_GROUP_H_
#define RADIO_BUTTON_GROUP_H_

#include <string>
#include <vector>
#include <QGridLayout>
#include <QRadioButton>
#include <QString>
#include <QWidget>

class RadioButtonGroup : public QWidget {
 public:
  RadioButtonGroup();

  void Reset();

  void SetAnswers(const std::vector<QString>& answers);
  const std::string& GetChosenAnswer() const;
  void SetStyle();

  void ConnectButtons();

 private:
  QGridLayout* layout_;
  std::vector<QRadioButton*> answers_;
  std::string chosen_answer_;
};

#endif  // RADIO_BUTTON_GROUP_H_
