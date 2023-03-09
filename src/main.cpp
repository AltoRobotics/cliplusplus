#include "spdlog/spdlog.h"
#include "version.h"
#include <reproc/run.h>

int main()
{
  // Use the default logger (stdout, multi-threaded, colored)
  spdlog::info("Hello, {} {}!", "World", BUILD_VERSION);

  const char *args[] = { "echo", "Hello, world!", NULL };
  return reproc_run(args, (reproc_options){ 0 });
}
