#include "view.h"

View::View(const std::shared_ptr<AbstractController>& controller) :
    controller_(controller) {}
