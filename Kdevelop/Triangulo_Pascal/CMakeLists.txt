cmake_minimum_required(VERSION 3.0)

project(triangulo_pascal LANGUAGES C)

add_executable(triangulo_pascal main.c)

install(TARGETS triangulo_pascal RUNTIME DESTINATION bin)
