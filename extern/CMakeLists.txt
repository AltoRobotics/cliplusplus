cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

include(FetchContent)

message("INSTALLING DEPENDENCIES")
set(EXTERNAL_DIR
    ${CMAKE_CURRENT_LIST_DIR}
    CACHE PATH "")
message(" EXTERNAL DIR " ${EXTERNAL_DIR})

# Prefer pthread over system thread - DEVONO stare prima del find_package!
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

#
# FMT
#
FetchContent_Declare(
  extern_fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 9.1.0)
FetchContent_MakeAvailable(extern_fmt)

#
# SPDLOG
#
FetchContent_Declare(
  extern_spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.11.0)
FetchContent_MakeAvailable(extern_spdlog)

#
# FMT
#
FetchContent_Declare(
  extern_catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.3.2)
FetchContent_MakeAvailable(extern_catch)

#
# REPROC
#
FetchContent_Declare(
  extern_reproc
  GIT_REPOSITORY http://gitlab.com/eidheim/tiny-process-library
  GIT_TAG v2.0.4)
FetchContent_MakeAvailable(extern_reproc)

message("INSTALLING DEPENDENCIES DONE")
