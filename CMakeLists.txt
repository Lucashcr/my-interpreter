cmake_minimum_required(VERSION 3.15)
project(Interp)

add_executable(
    Interp
    "logger/logger.cpp"
    main.cpp
)

target_compile_features(Interp PRIVATE cxx_std_17)