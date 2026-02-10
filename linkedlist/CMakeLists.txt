cmake_minimum_required(VERSION 4.1)
project(linkedlist)

set(CMAKE_CXX_STANDARD 20)

add_executable(linkedlist main.cpp
        model/servis_model.h
        include/helper.h
        src/helper.cpp
        storage/option_storage.h
        include/program.h
        view/program.cpp
        storage/servis_storage.h
)
