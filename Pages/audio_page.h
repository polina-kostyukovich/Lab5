#ifndef AUDIO_PAGE_H_
#define AUDIO_PAGE_H_

// #include <QMediaPlayer>
#include <QTextEdit>

#include "base_page.h"

class AudioPage : public BasePage {
 public:
  explicit AudioPage(AbstractView* view);

  void ManageLayout() override;
  void ConnectWidgets() override;
  void SetWidgetsStyle() override;

  const std::string& GetAnswer() const override;

  void ClearAnswer();

 private:
  QPushButton* play_;
  QPushButton* stop_;
  QTextEdit* answer_;
  std::string string_answer_;
};

#endif  // AUDIO_PAGE_H_
