cmake_minimum_required(VERSION 3.11)
project(Interp)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(
    Interp
    "logger/Logger.cpp"
    "nodes/location/Location.cpp"
    "nodes/file/File.cpp"
    "nodes/term/Term.cpp"
    "nodes/datatypes/str/Str.cpp"
    "nodes/statements/print/Print.cpp"
    main.cpp
)

target_compile_features(Interp PRIVATE cxx_std_17)
target_link_libraries(Interp PRIVATE nlohmann_json::nlohmann_json)
