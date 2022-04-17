#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <memory>

#include "abstract_controller.h"
#include "../Model/model.h"
#include "../View/view.h"

class Controller : public AbstractController {
 public:
  static std::shared_ptr<Controller> GetController();
  void Run();

 private:
  Controller();

 private:
  static std::shared_ptr<Controller> controller_;

  std::unique_ptr<Model> model_;
  std::unique_ptr<View> view_;
};

#endif  // CONTROLLER_H_
