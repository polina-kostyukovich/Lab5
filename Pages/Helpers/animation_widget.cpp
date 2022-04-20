#include "animation_widget.h"

AnimationWidget::AnimationWidget() :
    graphics_view_(new QGraphicsView(this)),
    scene_(new QGraphicsScene(this)),
    timer_(new QTimer(this)) {
  upset_images_.emplace_back(QPixmap(":Pages/Pictures/Upset/upset-0000.jpg"));
  upset_images_.emplace_back(QPixmap(":Pages/Pictures/Upset/upset-0001.jpg"));
  upset_images_.emplace_back(QPixmap(":Pages/Pictures/Upset/upset-0002.jpg"));
  upset_images_.emplace_back(QPixmap(":Pages/Pictures/Upset/upset-0003.jpg"));
  upset_images_.emplace_back(QPixmap(":Pages/Pictures/Upset/upset-0004.jpg"));
  upset_images_.emplace_back(QPixmap(":Pages/Pictures/Upset/upset-0005.jpg"));
  upset_images_.emplace_back(QPixmap(":Pages/Pictures/Upset/upset-0006.jpg"));
  upset_images_.emplace_back(QPixmap(":Pages/Pictures/Upset/upset-0007.jpg"));
  upset_images_.emplace_back(QPixmap(":Pages/Pictures/Upset/upset-0008.jpg"));
  upset_images_.emplace_back(QPixmap(":Pages/Pictures/Upset/upset-0009.jpg"));

  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0000.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0001.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0002.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0003.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0004.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0005.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0006.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0007.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0008.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0009.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0010.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0011.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0012.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0013.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0014.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0015.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0016.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0017.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0018.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0019.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0020.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0021.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0022.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0023.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0024.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0025.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0026.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0027.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0028.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0029.jpg"));
  happy_images_.emplace_back(QPixmap(":Pages/Pictures/Happy/happy-0030.jpg"));

  timer_->setInterval(50);
  connect(timer_, &QTimer::timeout, this, [&]{
    if (is_image_happy_) {
      scene_->addPixmap(happy_images_[current_image_ % happy_images_.size()]);
    } else {
      scene_->addPixmap(upset_images_[current_image_ % upset_images_.size()]);
    }
    graphics_view_->setScene(scene_);
    ++current_image_;
  });
}

void AnimationWidget::ShowHappy() {
  is_image_happy_ = true;
  graphics_view_->setVisible(true);
  timer_->start();
}

void AnimationWidget::ShowUnhappy() {
  is_image_happy_ = false;
  graphics_view_->setVisible(true);
  timer_->start();
}

void AnimationWidget::Hide() {
  graphics_view_->setVisible(false);
  scene_->clear();
  timer_->stop();
  current_image_ = 0;
}

void AnimationWidget::SetSize(int width, int height) {
  resize(width, height);
  graphics_view_->resize(width, height);
}
