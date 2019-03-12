#include <iostream>

template <class Entry>
class Binary_tree {
 public:
  Binary_tree();

  // accessor function
  bool empty() const;
  int size() const;

  // mutator function
  void clear();
  int height() const;
  void insert(const Entry &);

  // traversal
  void preorder(void (*visit)(Entry &));
  void inorder(void (*visit)(Entry &));
  void postorder(void (*visit)(Entry &));

  // constructor
  Binary_tree(const Binary_tree<Entry> &origin);  // copy constructor
  ~Binary_tree();                                 // deconstructor

  // operation overloding
  Binary_tree &operator=(const Binary_tree<Entry> &otigin);

 private:
  struct Binary_node<Entry> root;
  void recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
  void recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));
  void recursive_postorder(Binary_node<Entry> *sub_root,
                           void (*visit)(Entry &));
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
