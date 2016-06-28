cmake_minimum_required(VERSION 3.4)
project(hci)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11")

set(SOURCE_FILES

    main.cpp

    cmd_pack.cpp cmd_pack.h cmd_defs.h
    acl_data_pack.cpp acl_data_pack.h acl_data_defs.h
)

add_executable(hci ${SOURCE_FILES})
