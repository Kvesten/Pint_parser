#include "settings.h"

Settings::Settings(int argc, const char *argv[]) {
  std::string args[argc];
  for (size_t i = 0; i < argc; i++)
    args[i] = argv[i];
  for (size_t i = 0; i < argc - 1; i++) {
    if (args[i] == "-file") {
      this->use_file = 1;
      this->filename = args[i + 1];
    }
  }
}
