cmake_minimum_required(VERSION 3.22)
project(HW2)

set(CMAKE_CXX_STANDARD 14)

add_executable(HW2 String.cpp String.h Vector.h main.cpp Form.h Control.h Control.cpp Label.h CheckBox.h RadioButton.h TextBox.h ListBox.h Panel.h Form.cpp CheckBox.cpp Label.cpp ListBox.cpp RadioButton.cpp TextBox.cpp Panel.cpp)
