#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBinarySearchTreeRecursive(const vector<Node>& tree, int ind, int min, int max) {
  
  if (ind == -1) return true;
  // = in max is because of possibility of duplicates, but only in right subtree

  if (ind != 0 and (tree[ind].key < min or tree[ind].key > max)) return false;

  if (!IsBinarySearchTreeRecursive(tree, tree[ind].left, min, tree[ind].key - 1) or
        !IsBinarySearchTreeRecursive(tree, tree[ind].right, tree[ind].key, max))
    return false;

  return true;
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
  if (tree.size() == 0) return true;
  return IsBinarySearchTreeRecursive(tree, 0, INT_MIN, INT_MAX);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
