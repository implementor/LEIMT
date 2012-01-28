project(leimt)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(leimt_SRCS leimt.cpp main.cpp dbobj.cpp)
qt4_automoc(${leimt_SRCS})
add_executable(leimt ${leimt_SRCS})
target_link_libraries(leimt ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
