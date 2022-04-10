#ifndef MODEL_H_
#define MODEL_H_

#include <memory>

#include "../View/view.h"

class Model {
 public:
  explicit Model(const std::shared_ptr<View>& view);

 private:
  std::shared_ptr<View> view_;
};

#endif  // MODEL_H_
