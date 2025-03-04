cmake_minimum_required(VERSION 3.15)

project(
    brainiac
    VERSION 1.0.0
    DESCRIPTION "Simple high performance proxy server."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

set(BUILD_EXECUTABLE ON)
set(BUILD_TESTS OFF)
set(INSTALL_BRAINIAC ON)

# Locate and verify if C++ Boost libraries are installed
find_package(Boost REQUIRED)
if(NOT Boost_FOUND)
    message(FATAL "C++ boost libraries not installed.")
endif()

# Locate and verify if OpenSSL libraries are installed
find_package(OpenSSL REQUIRED)
if(NOT OpenSSL_FOUND)
    message(FATAL "OpenSSL libraries not installed.")
endif()

# Build the proxy server
if(BUILD_EXECUTABLE)
    add_subdirectory(src)
endif()

# Build tests
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

# Install Brainiac
if(INSTALL_BRAINIAC)
    message(WARNING "Implement the installation logic here")
endif()

