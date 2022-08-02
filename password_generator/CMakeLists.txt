cmake_minimum_required(VERSION 3.3)

# Project
project(password_generator)
find_package(xtd REQUIRED)
add_sources(
  src/password_generator_form.h
  src/password_generator_form.cpp
)
target_type(GUI_APPLICATION)

# Install
install_component()
