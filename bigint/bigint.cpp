#include "bigint.hpp"

bigint::bigint() : data("0") {}

bigint::bigint(unsigned int n) {
  data = numToStr(n);
} 

bigint::bigint(int n) {
  if (n < 0)
    n = -n;
  data = numToStr(n);
}

bigint::bigint(const bigint& src) : data(src.data) {}

// Private constructor used internally only
bigint::bigint(std::string data) : data(data) {}

bigint::~bigint() {}

bigint& bigint::operator=(const bigint& src) {
  if (this != &src) {
    this->data = src.data;
  }
  return *this;
}

// Addition overloads
bigint bigint::operator+(const bigint& right) const {
  return bigint(addition(this->data, right.data));
}

bigint& bigint::operator+=(const bigint& right) {
  this->data = addition(this->data, right.data);
  return *this;
}

// Increment
bigint& bigint::operator++() {
  *this += 1;
  return *this;
}

bigint bigint::operator++(int) {
  bigint temp = *this;
  *this += 1;
  return temp;
}

// Comparison overloads
bool bigint::operator==(const bigint& right) const {
  return this->data == right.data;
}

bool bigint::operator!=(const bigint& right) const {
  return this->data != right.data;
}

bool bigint::operator<(const bigint& right) const {
  if (this->data.size() != right.data.size())
    return this->data.size() < right.data.size();
  return this->data < right.data;
}

bool bigint::operator<=(const bigint& right) const {
  if (this->operator==(right))
    return true;
  return this->operator<(right);
}

bool bigint::operator>(const bigint& right) const {
  if (this->data.size() != right.data.size())
    return this->data.size() > right.data.size();
  return this->data > right.data;
}

bool bigint::operator>=(const bigint& right) const {
  if (this->operator==(right))
    return true;
  return this->operator>(right);
}

// Shift operators
bigint bigint::operator<<(const bigint& right) const {
  bigint result = *this;
  if (*this == 0)
    return *this;
  for (bigint i; i < right; ++i) {
    result.data.push_back('0');
  }
  return result;
}

bigint& bigint::operator<<=(const bigint& right) {
  *this = *this << right;
  return *this;
}

bigint bigint::operator>>(const bigint& right) const {
  bigint result;
  if (right >= static_cast<unsigned int>(this->data.size()))
    return result;
  result = *this;
  for (bigint i; i < right; ++i) {
    result.data.pop_back();
  }
  return result;
}

bigint& bigint::operator>>=(const bigint& right) {
  *this = *this >> right;
  return *this;
}

std::string bigint::addition(const std::string& left, const std::string& right) const {
  std::string rev_left = reverseStr(left);
  std::string rev_right = reverseStr(right);
  std::string result;
  
  if (left.size() < right.size())
    addZeroes(rev_left, right.size() - left.size());
  else if (right.size() < left.size())
    addZeroes(rev_right, left.size() - right.size());
  
  unsigned int remainder = 0;
  for (size_t i = 0; i < rev_left.size(); i++) {
    unsigned int left_digit = charToNum(rev_left[i]);
    unsigned int right_digit = charToNum(rev_right[i]);
    int sum = left_digit + right_digit + remainder;

    if (sum > 9) {
      result.push_back((sum % 10) + '0');
      remainder = 1;
    }
    else {
      result.push_back(sum + '0');
      remainder = 0;
    }
  }
  if (remainder == 1)
    result.push_back(1 + '0');

  return reverseStr(result);
}

std::string bigint::numToStr(unsigned int n) const {
  std::ostringstream temp;
  temp << n;
  return temp.str();
}

unsigned int bigint::charToNum(char c) const {
  return c - '0';
}

std::string bigint::reverseStr(const std::string& original) const {
  return std::string(original.rbegin(), original.rend());
}

void bigint::addZeroes(std::string& src, size_t n) const {
  for (size_t i = 0; i < n; ++i) {
    src.push_back('0');
  }
}

std::string bigint::getData() const {
  return this->data;
}

std::ostream& operator<<(std::ostream& os, const bigint& b) {
  os << b.getData();
  return os;
}
