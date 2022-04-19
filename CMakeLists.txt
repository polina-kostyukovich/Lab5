cmake_minimum_required(VERSION 3.20)
project(Lab5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Lab5
        main.cpp
        Controller/controller.cpp
        Model/model.cpp
        Pages/base_page.cpp
        Pages/main_page.cpp
        Pages/Helpers/animation_widget.cpp
        Pages/Helpers/radio_button_group.cpp
        Pages/Helpers/score_widget.cpp
        Pages/pick_an_option_page.cpp
        resources.qrc
        View/abstract_view.h
        View/view.cpp
        )
target_link_libraries(Lab5
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
