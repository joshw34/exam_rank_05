#pragma once

#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

class set {
  public:
    set() = delete;
    set(searchable_bag&);
    set(const set&);
    set& operator=(const set&);
    ~set();

    void insert(int);
    void insert(int*, int);
    bool has(int) const;
    searchable_bag& get_bag() const;
    void print() const;
    void clear();
  private:
    searchable_bag& data;
};
