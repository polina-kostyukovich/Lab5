#include <QApplication>

#include "Controller/controller.h"
#include "View/view.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);

  auto controller = Controller::GetController();
  auto model = std::make_unique<Model>();
  controller->SetModel(std::move(model));
  auto view = std::make_unique<View>(controller);
  controller->SetView(std::move(view));

  controller->Run();

  return QApplication::exec();
}
