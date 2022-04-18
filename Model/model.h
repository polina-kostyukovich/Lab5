#ifndef MODEL_H_
#define MODEL_H_

#include <memory>

class Model {
 public:
  Model() = default;

  int GetScore() const;
  void SetScore(int score);

 private:
  int score_;
};

#endif  // MODEL_H_
