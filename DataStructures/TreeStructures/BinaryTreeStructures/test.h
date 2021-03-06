#include <iostream>

template <class T>
struct node {
  T data;
  node *left;
  node *right;
};

template <class T>
class list {
 public:
  list();
  void clear(node<T> *&x);

 private:
  node<T> root;
};

template <class T>
list<T>::list() {
  root = NULL;
}

template <class T>
void list<T>::clear(node<T> *&x) {
  if (!x) return;
  clear(x->left);
  clear(x->right);
};