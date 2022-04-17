#include "controller.h"

std::shared_ptr<Controller> Controller::controller_ = nullptr;

std::shared_ptr<Controller> Controller::GetController() {
  if (controller_ == nullptr) {
    auto controller = new Controller;
    controller_ = std::shared_ptr<Controller>(controller);
  }
  return controller_;
}

void Controller::Run() {
  view_->show();
}

Controller::Controller() {
  view_ = std::make_unique<View>(std::shared_ptr<AbstractController>(controller_));
  model_ = std::make_unique<Model>();
}
