#include "spdlog/spdlog.h"
#include "version.h"
#include "process.hpp"

using namespace std;
using namespace TinyProcessLib;


int main()
{
  // Use the default logger (stdout, multi-threaded, colored)
  spdlog::info("Hello, {} {}!", "World", BUILD_VERSION);

  spdlog::info("Example 1a - the mandatory Hello World through a command");
  Process process1a("echo Hello World", "", [](const char *bytes, size_t n) {
    spdlog::info("Output from stdout: {} ", string(bytes, n));
  });
  auto exit_status = process1a.get_exit_status();
  spdlog::info("Example 1a process returned: {} ({})", exit_status, (exit_status == 0 ? "success" : "failure"));
}
