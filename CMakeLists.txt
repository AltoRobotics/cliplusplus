cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(
  cliPlusPlus_prj
  VERSION 0.0.1
  LANGUAGES CXX C)
message(STATUS "cliPlusPlus_prj Version: ${PROJECT_VERSION} ")

include(cmake/StandardProjectSettings.cmake)

# You need to set the dafaults to propagate to subdirectories
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Link this 'library' to set the c++ standard / compile-time options requested
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# enable cache system
include(cmake/Cache.cmake)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# enable doxygen
include(cmake/Doxygen.cmake)
enable_doxygen()

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

# allow for static analysis options
include(cmake/gitversion.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_TESTING "Enable Test Builds" ON)

# Very basic PCH example
option(ENABLE_PCH "Enable Precompiled Headers" OFF)
if(ENABLE_PCH)
  # This sets a global PCH parameter, each project will build its own PCH, which is a good idea if any #define's change
  #
  target_precompile_headers(
    project_options
    INTERFACE
    <vector>
    <string>
    <map>
    <utility>)
endif()

add_subdirectory(extern)

if(ENABLE_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()

add_subdirectory(src)

option(ENABLE_UNITY "Enable Unity builds of projects" OFF)
if(ENABLE_UNITY)
  # Add for any project you want to apply unity builds for
  set_target_properties(cliPlusPlus PROPERTIES UNITY_BUILD ON)
endif()

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
  cliPlusPlus_prj.cmake
  VERSION 0.1.0
  COMPATIBILITY SameMajorVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cliPlusPlus_prj.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake)
