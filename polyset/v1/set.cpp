#include "set.hpp"

set::set(searchable_bag& src) : data(src) {}

set::set(const set& src) : data(src.data) {}

set& set::operator=(const set& src) {
  // Function does nothing (reference can not be rebound)
  (void)src;
  return *this;
}

set::~set() {}

void set::insert(int n) {
  if (!this->has(n))
    data.insert(n);
}

void set::insert(int* arr, int size) {
  for (int i = 0; i < size; ++i)
    this->insert(arr[i]);
}

bool set::has(int n) const {
  return data.has(n);
}

searchable_bag& set::get_bag() const {
  return this->data;
}

void set::print() const {
  return this->data.print();
}

void set::clear() {
  return this->data.clear();
}
