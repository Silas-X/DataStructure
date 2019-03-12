#include <iostream>

template <class Entry>
class Binary_tree {
 public:
  Binary_tree();

 private:
  struct Binary_node<Entry> root;
};

template <class Entry>
struct Binary_node {
  // data members;
  Entry data;
  Binary_node<Entry> *left;
  Binary_node<Entry> *right;
  // constructors
  Binary_node();
  Binary_node(const Entry &x);
};

template <class Entry>
Binary_tree<Entry>::Binary_tree() {
  root = NULL;
}