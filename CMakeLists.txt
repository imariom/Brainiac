cmake_minimum_required(VERSION 3.20)
project(CppTutorial)

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS        OFF)  # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost REQUIRED)

if(Boost_FOUND)
    add_executable(proxy_server main.cc)
    target_include_directories(proxy_server PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(proxy_server Boost::boost)
endif()

