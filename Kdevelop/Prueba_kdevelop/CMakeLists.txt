cmake_minimum_required(VERSION 3.0)

project(prueba_kdevelop LANGUAGES C)

add_executable(prueba_kdevelop main.c)

install(TARGETS prueba_kdevelop RUNTIME DESTINATION bin)
