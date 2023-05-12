#ifndef MYFUNC_H_INCLUDED
#define MYFUNC_H_INCLUDED
#pragma once

#include "include/point/point.h"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Для хранения линии и кол-во точек на ней
struct Out_line {
  Point *point1 = nullptr, *point2 = nullptr;
  uint16_t count_point = 0;
};

struct Min_max_line {
  Out_line min, max;
};

void pars_file(const std::string &filename, std::vector<Point *> &vec);
void human_input(std::vector<Point *> &vec);
void auto_input(std::vector<Point *> &vec);
void file_input(std::vector<Point *> &vec);
Min_max_line *parse_vector_point(const std::vector<Point *> &vec);
void save_from_file(const std::vector<Point *> &vec,
                    const std::string &filename);
void print_min_max_line(const Min_max_line &out);

#endif  // MYFUNC_H_INCLUDED
