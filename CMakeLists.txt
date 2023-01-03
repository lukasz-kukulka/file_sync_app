cmake_minimum_required(VERSION 3.14)

project(FilesSync LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_subdirectory(thirdparty)
#add_subdirectory(src)
#add_subdirectory(ut)

include(FetchContent)
FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
  )
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)

FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(json)

set(SRC_LIST
    main.cpp
    src/machine.cpp
    src/synchronizer.cpp
    src/machinesSync.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(FilesSync PRIVATE nlohmann_json::nlohmann_json)
# target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra -O3)
