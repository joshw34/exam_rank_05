#pragma once

#include <string>
#include <sstream> // IWYU pragma: keep
#include <stddef.h>
#include <ostream>

class bigint {
  public:
    bigint();
    bigint(unsigned int);
    bigint(int);
    bigint(const bigint&);
    ~bigint();

    bigint& operator=(const bigint&);

    // Addition
    bigint operator+(const bigint&) const;
    bigint& operator+=(const bigint&);

    // Increment
    bigint& operator++();
    bigint operator++(int);

    // Comparison
    bool operator==(const bigint&) const;
    bool operator!=(const bigint&) const;
    bool operator<(const bigint&) const;
    bool operator<=(const bigint&) const;
    bool operator>(const bigint&) const;
    bool operator>=(const bigint&) const;

    // Shift operators
    bigint operator<<(const bigint&) const;
    bigint& operator<<=(const bigint&);
    bigint operator>>(const bigint&) const;
    bigint& operator>>=(const bigint&);

    std::string getData() const;

  private:
    std::string data;
    bigint(std::string);
    std::string addition(const std::string& left, const std::string& right) const;
    std::string numToStr(unsigned int) const;
    unsigned int charToNum(char c) const;
    std::string reverseStr(const std::string&) const;
    void addZeroes(std::string&, size_t) const;
};

std::ostream& operator<<(std::ostream& os, const bigint& b);
