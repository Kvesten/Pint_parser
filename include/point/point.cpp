#include "point.h"

Point::Point(const int32_t x, const int32_t y) {
  this->x = x;
  this->y = y;
}

bool Point::operator!=(const Point &other) const {
  return this->x != other.x or this->y != other.y;
}

bool Point::operator==(const Point &other) const {
  return this->x == other.x and this->y == other.y;
}
