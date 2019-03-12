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
  void preorder(void (*visit)(Binary_node<Entry> *&));
  void inorder(void (*visit)(Binary_node<Entry> *&));
  void postorder(void (*visit)(Binary_node<Entry> *&));
  void levelOrder(void (*visit)(Binary_node<Entry> *&));
  // constructor
  Binary_tree(const Binary_tree<Entry> &origin);  // copy constructor
  ~Binary_tree();                                 // deconstructor

  // operation overlodes
  Binary_tree &operator=(const Binary_tree<Entry> &origin);

 private:
  struct Binary_node<Entry> root;
  int treeSize;
  int treeHeight;
  // auxiliary function
  void recursive_preorder(Binary_node<Entry> *sub_root,
                          void (*visit)(Binary_node<Entry> *&));
  void recursive_inorder(Binary_node<Entry> *sub_root,
                         void (*visit)(Binary_node<Entry> *&));
  void recursive_postorder(Binary_node<Entry> *sub_root,
                           void (*visit)(Binary_node<Entry> *&));
  void countNodes(const Binary_node<Entry> *&);
  void countHeight(const Binary_node<Entry> *&);
  void destroyNode(const Binary_node<Entry> *&);
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
