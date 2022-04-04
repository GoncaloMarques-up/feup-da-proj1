cmake_minimum_required(VERSION 3.21)
project(projeto_DA)

set(CMAKE_CXX_STANDARD 14)

add_executable(projeto_DA main.cpp 
              src/Estafeta.cpp includes/Estafeta.h
              src/Armazem.cpp includes/Armazem.h
              )

