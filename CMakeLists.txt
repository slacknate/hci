cmake_minimum_required(VERSION 3.4)
project(hci)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++11")

set(SOURCE_FILES

    main.cpp

    cmd_pkt.cpp cmd_pkt.h cmd_defs.h
    acl_data_pkt.cpp acl_data_pkt.h acl_data_defs.h
    sync_data_pkt.cpp sync_data_pkt.h sync_data_defs.h
)

add_executable(hci ${SOURCE_FILES})
