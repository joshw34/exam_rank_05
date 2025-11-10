#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}

vect2::vect2(int x, int y) : x(x), y(y) {}

vect2::vect2(const vect2& src) : x(src.x), y(src.y) {}

vect2::~vect2() {}

vect2& vect2::operator=(const vect2& src) {
  if (this != &src) {
    this->x = src.x;
    this->y = src.y;
  }
  return *this;
}

vect2 vect2::operator+(const vect2& right) const {
  vect2 result(*this);
  return result += right;
}

vect2& vect2::operator+=(const vect2& right) {
  this->x += right.x;
  this->y += right.y;
  return *this;
}

vect2 vect2::operator-(const vect2& right) const {
  vect2 result(*this);
  return result -= right;
}

vect2 vect2::operator-() const {
  return vect2(-(this->x), -(this->y));
}

vect2& vect2::operator-=(const vect2& right) {
  this->x -= right.x;
  this->y -= right.y;
  return *this;
}

vect2 vect2::operator*(int n) const {
  vect2 result(*this);
  return result *= n;
}

vect2& vect2::operator*=(int n) {
  this->x *= n;
  this->y *= n;
  return *this;
}

vect2& vect2::operator++() {
  this->x++;
  this->y++;
  return *this;
}

vect2 vect2::operator++(int) {
  vect2 result(*this);
  ++(*this);
  return result;
}

vect2& vect2::operator--() {
  this->x--;
  this->y--;
  return *this;
}

vect2 vect2::operator--(int) {
  vect2 result(*this);
  --(*this);
  return result;
}

bool vect2::operator==(const vect2& right) const {
  return this->x == right.x && this->y == right.y;
}

bool vect2::operator!=(const vect2& right) const {
  return !(*this == right);
}

int& vect2::operator[](int index) {
  return index == 0 ? x : y;
}

int vect2::operator[](int index) const {
  return index == 0 ? x : y;
}

vect2 operator*(int n, const vect2& right) {
  vect2 result(right);
  return result * n;
}

std::ostream& operator<<(std::ostream& os, const vect2& v) {
  os << "{" << v[0] << ", " << v[1] << "}";
  return os;
}
