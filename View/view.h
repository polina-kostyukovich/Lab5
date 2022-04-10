#ifndef VIEW_H_
#define VIEW_H_

#include <memory>
#include <QWidget>

#include "../Controller/abstract_controller.h"

class View : public QWidget {
 public:
  explicit View(const std::shared_ptr<AbstractController>& controller);

 private:
  std::shared_ptr<AbstractController> controller_;
};

#endif  // VIEW_H_
