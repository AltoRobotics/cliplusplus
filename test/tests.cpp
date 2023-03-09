
#include "catch2/catch_test_macros.hpp"
#include "fmt/core.h"
#include "process.hpp"

using namespace TinyProcessLib;


TEST_CASE("Runs")
{
  Process process1("../src/cliPlusPlus", "", [](const char *bytes, size_t n) {});
  auto exit_status = process1.get_exit_status();
  REQUIRE(process1.get_exit_status() == 0);
}

TEST_CASE("True")
{
  Process process1("../src/true", "", [](const char *bytes, size_t n) {});
  auto exit_status = process1.get_exit_status();
  REQUIRE(process1.get_exit_status() == 0);
}


TEST_CASE("False")
{
  Process process1("../src/false", "", [](const char *bytes, size_t n) {});
  auto exit_status = process1.get_exit_status();
  REQUIRE(process1.get_exit_status() == 1);
}
