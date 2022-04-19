#ifndef RADIO_BUTTON_GROUP_H_
#define RADIO_BUTTON_GROUP_H_

#include <vector>
#include <QGridLayout>
#include <QRadioButton>
#include <QWidget>

class RadioButtonGroup : public QWidget {
 public:
  RadioButtonGroup();

  int GetChosenAnswer() const;
  void SetStyle();

  void ConnectButtons();

 private:
  QGridLayout* layout_;
  std::vector<QRadioButton*> answers_;
  int chosen_answer_{-1};
};

#endif  // RADIO_BUTTON_GROUP_H_
