cmake_minimum_required(VERSION 3.14)

project(FilesSync LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_subdirectory(src)
#add_subdirectory(ut)

include(FetchContent)
FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
  )
FetchContent_MakeAvailable(googletest)

# FetchContent_Declare(fmt
#   GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#   GIT_TAG master
# )

#FetchContent_MakeAvailable(fmt)

add_compile_definitions(RELEASE) # adds compile definition

find_package(Threads)

set(SRC_LIST
    main.cpp
    # src/fileInfo.cpp
    # src/fileContainer.cpp
    # src/fileSynchronization.cpp
    # src/folder.cpp
    # src/fileCheckSum.cpp
    # src/SHA256.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
# target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra -O3)

# target_link_libraries(${PROJECT_NAME}
#    PRIVATE
#       ${CMAKE_THREAD_LIBS_INIT}
#       fmt::fmt)