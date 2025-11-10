#pragma once

#include <ostream>

class vect2 {
  public:
    vect2();
    vect2(int, int);
    vect2(const vect2&);
    ~vect2();

    vect2& operator=(const vect2&);

    vect2 operator+(const vect2&) const;
    vect2& operator+=(const vect2&);

    vect2 operator-(const vect2&) const;
    vect2 operator-() const;
    vect2& operator-=(const vect2&);

    vect2 operator*(int) const;
    vect2& operator*=(int);

    vect2& operator++();
    vect2 operator++(int);
    vect2& operator--();
    vect2 operator--(int);

    bool operator==(const vect2& right) const;
    bool operator!=(const vect2& right) const;

    int& operator[](int);
    int operator[](int) const;

  private:
    int x;
    int y;
};

vect2 operator*(int, const vect2&);
std::ostream& operator<<(std::ostream& os, const vect2& v);
