cmake_minimum_required(VERSION 3.14)

project(FilesSync LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_subdirectory(thirdparty)
# add_subdirectory(src)
# add_subdirectory(ut)
# include_directories(${PROJECT_SOURCE_DIR}/src)
# include_directories(${PROJECT_SOURCE_DIR}/ut)

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
    src/Machine.cpp
    src/Synchronizer.cpp
    src/MachinesSync.cpp
    src/FileInfo.cpp
    src/Time.cpp
)

set(TEST_LIST
    ut/FileInfoTests.cpp
    ut/MachineSyncTests.cpp
    ut/MachineTests.cpp
    ut/SynchronizerTests.cpp
    ut/TimeTests.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(FilesSync PRIVATE nlohmann_json::nlohmann_json)
# target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra -O3)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(${PROJECT_NAME}-gt ${TEST_LIST})
target_link_libraries(${PROJECT_NAME}-gt gtest_main)
enable_testing()
add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-gt)
