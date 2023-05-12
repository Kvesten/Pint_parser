#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#pragma once

#include <cstdint>
class Point {
public:
  int32_t x, y;
  bool operator!=(const Point &other) const;
  bool operator==(const Point &other) const;
  Point(const int32_t x, const int32_t y);
};

#endif  // POINT_H_INCLUDED
