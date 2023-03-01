cmake_minimum_required(VERSION 3.24)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


add_executable(lab4 main.cpp Figure.cpp Figure.h Circle.cpp Circle.h AppCore.cpp AppCore.h Triangle.cpp Triangle.h Rectangle.cpp Rectangle.h FigureComposite.cpp FigureComposite.h Dot.cpp Dot.h Line.cpp Line.h Star.cpp Star.h Snapshot.cpp Snapshot.h)

target_link_libraries(lab4 sfml-graphics sfml-audio)
