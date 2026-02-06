cmake_minimum_required(VERSION 4.1)
project(semester_02)

set(CMAKE_CXX_STANDARD 26)

add_executable(semester_02
        minggu-01/main.cpp
        minggu-01/model/model_admin.h
        minggu-01/database/db_admin.h
        minggu-01/view/view_admin.h
        minggu-01/database/option.h
        minggu-01/helper/helper.h
        minggu-02/main.cpp
        minggu-02/database/database_mahasiswa.h
)
