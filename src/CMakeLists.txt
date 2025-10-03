cmake_minimum_required (VERSION 3.8)
project("Help-Get-Name")

add_executable("Help-Get-Name" main.cpp "sroce/rank/rank.hpp" "sroce/rank/rank.cpp")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET hgnReader PROPERTY CXX_STANDARD 20)
endif()