cmake_minimum_required(VERSION 3.6)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(yakovlev_m_y)

include(cmake/build_prefix.cmake)

include_directories(prj.lab prj.thirdparty)

add_subdirectory(prj.lab)
add_subdirectory(prj.test)