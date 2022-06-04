cmake_minimum_required(VERSION 2.4)

project(rocket)

add_executable(rocket 
    main.cpp
    logic/DrawLogic.cpp
    logic/AtomicFunctions.cpp
    )

set_property(TARGET rocket PROPERTY CXX_STANDARD 17)
