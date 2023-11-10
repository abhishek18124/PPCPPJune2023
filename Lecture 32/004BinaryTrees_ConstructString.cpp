#include<iostream>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

TreeNode* buildTree() {

	int val;
	cin >> val;

	// base case

	if (val == -1) {
		// construct an empty tree and return pointer to its root TreeNode
		return NULL;
	}

	// recursive case

	// 1. construct the root val using the first value of the given preOrder traversal

	TreeNode* root = new TreeNode(val);

	// 2. ask your friend to construct the leftSubtree from the preOrder traversal of the leftSubtree

	root->left = buildTree();

	// 3. ask your friend to construct the rightSubtree from the preOrder traversal of the rightSubtree

	root->right = buildTree();

	return root;

}

string tree2str(TreeNode* root) {

	// base case

	if (root == NULL) {

		return "";

	}

	// recursive case

	// 1. recursively, build the string corresponding to the leftSubtree
	string leftStr = tree2str(root->left);

	// 2. recursively, build the string corresponding to the rightSubtree
	string rightStr = tree2str(root->right);

	if (root->left != NULL and root->right != NULL) { // or leftStr != "" and rightStr != ""

		return to_string(root->val) + "(" + leftStr + ")(" + rightStr + ")";

	} else if (root->left != NULL) { // or leftStr != ""

		return to_string(root->val) + "(" + leftStr + ")";

	} else if (root->right != NULL) { // or rightStr != ""

		return to_string(root->val) + "()(" + rightStr + ")";

	} else { // root->left == NULL and root->right == NULL

		return to_string(root->val);

	}


}


int main() {

	TreeNode* root = buildTree();
	cout << tree2str(root) << endl;

	return 0;
}