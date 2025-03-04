set(BRAINIAC_SOURCES
    main.cc
    brainiac/ProxyServer.cc
    brainiac/ProxySession.cc
    brainiac/ServerConfig.cc)

add_executable(brainiac ${BRAINIAC_SOURCES})
target_include_directories(brainiac PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(brainiac PRIVATE ${Boost_INCLUDE_DIRS})
