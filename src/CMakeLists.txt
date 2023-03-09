include(GNUInstallDirs)
include(GenerateExportHeader)

add_executable(cliPlusPlus)
target_sources(cliPlusPlus PRIVATE main.cpp)
target_link_libraries(
  cliPlusPlus
  PRIVATE project_options
          project_warnings
          spdlog::spdlog
          tiny-process-library)
target_include_directories(cliPlusPlus PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
define_file_basename_for_sources(cliPlusPlus)

add_executable(true)
target_sources(true PRIVATE true.cpp)

add_executable(false)
target_sources(false PRIVATE false.cpp)

# add this only for libraries generate_export_header(cliPlusPlus)

set_target_properties(cliPlusPlus PROPERTIES SOVERSION 1 VERSION 1.0.0)
target_compile_definitions(cliPlusPlus PRIVATE PZ_ENABLE_ASSERTS)

# install stuff
install(
  TARGETS cliPlusPlus
          spdlog
          fmt
          project_options
          project_warnings
  EXPORT cliPlusPlusConfig)
install(EXPORT cliPlusPlusConfig DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake)

configure_file(version.h.in version.h @ONLY)
