#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED
#pragma once

#include <string>
struct Settings {
  bool use_file = 0;
  std::string filename;
  Settings(int argc, char const *argv[]);
};

#endif  // SETTINGS_H_INCLUDED
