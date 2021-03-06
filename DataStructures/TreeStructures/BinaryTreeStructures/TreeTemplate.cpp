#include "TreeTemplate.h"
#include <iostream>
#include <queue>

template <typename Entry>
Binary_node<Entry>::Binary_node() {
  root = NULL;
}

template <typename Entry>
Binary_node<Entry>::Binary_node(const Entry& x) {
  data = x;
  left = NULL;
  right = NULL;
}

// Binary Tree

// Function:Constructors
template <typename Entry>
Binary_tree<Entry>::Binary_tree() {
  root = NULL;
  treeSize = 0;
}

template <class Entry>
Binary_tree<Entry>::Binary_tree(const Binary_tree<Entry>& origin)
// Post:build a new same tree as the origin.
// Uses: Recursive_copy
{
  if (!root) clear();
  if (!origin->root) {
    root = NULL
  };
  recursive_copy(root,
                 origin->root);  // TODO:Access the same class's private member?
                                 // If a client get a private variable address,
                                 // can it access that variable?
}
template <class Entry>
void Binary_tree<Entry>::recursive_copy(Binary_node<Entry>*& copyTree,
                                        Binary_node<Entry>*& originNode) {
  if (originNode) {
    if (!copyTree) copyTree = new Binary_node<Entry>;
    copyTree->data = originNode->data;
    recursive_copy(copyTree->left, originNode->left);
    recursive_copy(copyTree->left, originNode->right);
  }
}

//destructor
template <class Entry>
Binary_tree<Entry>::~Binary_tree() {
  clear();
}

//Operator =


template <typename Entry>
bool Binary_tree<Entry>::empty() const {
  return root == NULL;
}

// determine Size
template <typename Entry>
int Binary_tree<Entry>::size() const {
  treeSize = 0;
  preorder(countNodes);
  return treeSize;
}

template <typename Entry>
void Binary_tree<Entry>::countNodes(Binary_node<Entry>*& node) {
  if (node) treeSize++;
}

// clear
template <typename Entry>
void Binary_tree<Entry>::clear() {
  postorder(destroyNode);
}

template <typename Entry>
void Binary_tree<Entry>::destroyNode(Binary_node<Entry>*& node) {
  if (node) delete node;
  node = NULL;
  return;
}

template <typename Entry>
int Binary_tree<Entry>::height() const {
  treeHeight = 0;
  preorder(countHeight);
  return treeHeight;
}

// Function: Traversal
template <typename Entry>
void Binary_tree<Entry>::preorder(void (*visit)(Binary_node<Entry>*& node)) {
  recursive_preorder(root, visit);
}
template <class Entry>
void Binary_tree<Entry>::recursive_preorder(
    Binary_node<Entry>* sub_root, void (*visit)(Binary_node<Entry>*& node)) {
  if (sub_root == NULL) return;
  visit(sub_root);
  recursive_preorder(sub_root->left);
  recursive_preorder(sub_root->right);
}

template <typename Entry>
void Binary_tree<Entry>::inorder(void (*visit)(Binary_node<Entry>*& node)) {
  recursive_inorder(root, visit);
}
template <class Entry>
void Binary_tree<Entry>::recursive_inorder(
    Binary_node<Entry>* sub_root, void (*visit)(Binary_node<Entry>*& node)) {
  if (sub_root == NULL) return;
  recursive_inorder(sub_root->left);
  visit(sub_root);
  recursive_inorder(sub_root->right);
}

template <typename Entry>
void Binary_tree<Entry>::postorder(void (*visit)(Binary_node<Entry>*& node)) {
  recursive_postorder(root, visit);
}
template <class Entry>
void Binary_tree<Entry>::recursive_postorder(
    Binary_node<Entry>* sub_root, void (*visit)(Binary_node<Entry>*& node)) {
  if (sub_root == NULL) return;
  recursive_postorder(sub_root->left);
  recursive_postorder(sub_root->right);
  visit(sub_root);
}

template <typename Entry>
void Binary_tree<Entry>::countHeight(Binary_node<Entry>*& node) {
  treeHeight = 0;
  levelOrder(NULL);  // TODO:Can it pass a NULL to a pointer to function?
}

template <typename Entry>
void Binary_tree<Entry>::levelOrder(void (*visit)(Binary_node<Entry>*&)) {
  std::queue<struct Binary_node*> q;
  q.push(root);
  Binary_node<Entry>* current;
  int level = 0;
  while (!q.empty()) {
    int q_size = q.size();
    for (int i = 0; i < q_size; i++) {
      current = q.front();
      q.pop();
      visit(current);
      q.push(current->left);
      q.push(current->right);
    }
    level++;
  }
  treeHeight = level;
}