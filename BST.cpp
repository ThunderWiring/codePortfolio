/*
BST manipulation.
- check if a binary tree is a binary search tree(BST)
- print a BST in-order
*/
#include <limits.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <iostream>
using namespace std;
 
struct Node {
  Node* left;
  Node* right;
  int data;
  Node(int d) : left(NULL), right(NULL), data(d) {
  }
};
/************************************************************/
struct Tree {
  Node* root;
  Tree(Node* r) : root(r) {}
  //---------------------------------------------//
  void printInOrder(const Node* node) const {
    if(!node) {
      return;
    }
    printInOrder(node->left);
    cout << node->data << endl;
    printInOrder(node->right);
  }
  //---------------------------------------------//
  void add(int val, Node* node) {
    if(node == NULL) {
      Node* newNode = new Node(val);
      node = newNode;
      cout << "adding " << node->data << endl;
    } else if(val > node->data) {
      if(!node->right) {
        Node* newNode = new Node(val);
        node->right = newNode;
        return;
      }
      else add(val, node->right);
    } else if(val < node->data) {
      if(!node->left) {
        Node* newNode = new Node(val);
        node->left = newNode;
        return;
      }
      else add(val, node->left);
    } else return;
  }
};
/************************************************************/
bool isBST(Node* node, pair<int, int> range) {
  if(!node) {
    return false;
  } else if(!(node->data <= range.second && node->data >= range.first)) {
    return false;
  }
  isBST(node->left, make_pair(range.first, node->data));
  isBST(node->right, make_pair(node->data, range.second));
  return true;
}
/************************************************************/
int main() {
  Node n3 = Node(3);
  Tree t = Tree(&n3);
  t.add(2, t.root);
  t.add(12, t.root);
  t.add(112, t.root);
  t.add(22, t.root);
  t.printInOrder(t.root);
  cout << isBST(t.root, make_pair(INT_MIN, INT_MAX));
  return 0;
}