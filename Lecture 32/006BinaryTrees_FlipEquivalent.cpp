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


void printPreOrder(TreeNode* root) {

	// base case
	if (!root) { // root == NULL
		cout << -1 << " ";
		return;
	}

	// recursive case

	// 1. process the root TreeNode
	cout << root->val << " ";

	// 2. do the preOrder traversal of the leftSubtree
	printPreOrder(root->left);

	// 3. do the preOrder traversal of the rightSubtree
	printPreOrder(root->right);

}

bool flipEquiv(TreeNode* root1, TreeNode* root2) {

	// base case

	if (root1 == NULL and root2 == NULL) {
		return true;
	}

	// if (root1 == NULL) {
	// 	return false;
	// }

	// if (root2 == NULL) {
	// 	return false;
	// }

	if (root1 == NULL || root2 == NULL) {
		return false;
	}

	// recursive case

	if (root1->val != root2->val) {
		// root1 and root2 are not flip-equivalent
		return false;
	}

	// 1. perform a flip operation at the root node

	swap(root1->left, root1->right);

	if (flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right)) {
		return true;
	}

	swap(root1->left, root1->right); // backtracking

	// 2. do not perform flip operation at the root node

	if (flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right)) {
		return true;
	}

	// root1 and root2 are not flip equivalent

	return false;

}

int main() {

	TreeNode* root1 = buildTree();
	TreeNode* root2 = buildTree();

	flipEquiv(root1, root2) ? cout << "true" << endl :
	                               cout << "false" << endl;

	return 0;
}