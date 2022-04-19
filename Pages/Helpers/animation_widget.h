#ifndef ANIMATION_WIDGET_H_
#define ANIMATION_WIDGET_H_

#include <vector>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QTimer>
#include <QWidget>

class AnimationWidget : public QWidget {
 public:
  AnimationWidget();

  void SetSize(int width, int height);

  void ShowHappy();
  void ShowUnhappy();
  void Hide();

 private:
  QGraphicsView* graphics_view_;
  QGraphicsScene* scene_;
  std::vector<QPixmap> upset_images_;
  std::vector<QPixmap> happy_images_;
  QTimer* timer_;
  uint64_t current_image_{0};
  bool is_image_happy_;
};

#endif  // ANIMATION_WIDGET_H_
