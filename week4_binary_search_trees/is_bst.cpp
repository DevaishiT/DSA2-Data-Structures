#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

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

// can be done using the inorder traversal and check if ascending
// not in case of duplicates allowed in one subtree though
/*bool IsBinarySearchTreeRecursive(const vector<Node>& tree, int ind, int min, int max) {
  
  if (ind == -1) return true;
  if (ind != 0 and (tree[ind].key < min or tree[ind].key > max)) return false;

  return (IsBinarySearchTreeRecursive(tree, tree[ind].left, min, tree[ind].key - 1) and
        IsBinarySearchTreeRecursive(tree, tree[ind].right, tree[ind].key + 1, max));
}*/

void inorderTraversal(const vector<Node>& tree, int ind, vector<int> &in)
{
	if (ind == -1) return;
	inorderTraversal(tree, tree[ind].left, in);
	in.push_back(tree[ind].key);
	inorderTraversal(tree, tree[ind].right, in);
}

bool IsBinarySearchTree(const vector<Node>& tree) {

  // Implement correct algorithm here
  // if (tree.size() == 0) return true;
  // return IsBinarySearchTreeRecursive(tree, 0, INT8_MIN, INT8_MAX);

	if (tree.size() == 0) return true;
	vector<int> inorder;
	inorderTraversal(tree, 0, inorder);

	for(int i=0; i < inorder.size() - 1; i++)
		if (inorder[i] >= inorder[i+1])
			return false;

	return true;
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
