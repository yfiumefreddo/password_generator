cmake_minimum_required(VERSION 3.3)

# Project
project(password_generator)
find_package(xtd REQUIRED)
add_sources(
  src/form_password_generator.h
  src/form_password_generator.cpp
)
target_type(GUI_APPLICATION)

# Install
install_component()
