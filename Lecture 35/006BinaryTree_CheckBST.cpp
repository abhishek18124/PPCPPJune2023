/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

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

int findMinimum(TreeNode* root) {

	if (root == NULL) {
		return INT_MAX;
	}

	while (root->left != NULL) {
		root = root->left;
	}

	// root is at the leftmost node i.e. the minval node

	return root->val;


}

int findMaximum(TreeNode* root) {

	if (root == NULL) {
		return INT_MIN;
	}

	while (root->right != NULL) {
		root = root->right;
	}

	// root is at the rightmost node i.e. the maxval node

	return root->val;

}


bool isBST(TreeNode* root) {

	// base case

	if (root == NULL) {
		// empty tree is a BST
		return true;
	}

	// recursive case

	// 1. recursively check if the leftSubtree is a BST
	bool leftIsBST = isBST(root->left);

	// 2. recursively check if the rightSubtree is a BST
	bool rightIsBST = isBST(root->right);

	// 3. check if the BST prop. is satisfied at the root
	bool rootIsBST = root->val > findMaximum(root->left) and root->val < findMinimum(root->right) ? true : false;

	return leftIsBST and rightIsBST and rootIsBST;

}

class triple {


public:
	bool bst;
	int minVal;
	int maxVal;

};

triple isBSTEfficient(TreeNode* root) {

	triple t;

	// base case

	if (root == NULL) {
		// empty tree is a BST

		t.bst = true;
		t.minVal = INT_MAX;
		t.maxVal = INT_MIN;

		return t;
	}

	// recursive case

	// 1. recursively check if the leftSubtree is a BST
	triple left = isBSTEfficient(root->left);

	// 2. recursively check if the rightSubtree is a BST
	triple right = isBSTEfficient(root->right);

	// 3. check if the BST prop. is satisfied at the root
	bool rootIsBST = root->val > left.maxVal and root->val < right.minVal ? true : false;

	t.bst = left.bst and right.bst and rootIsBST;
	t.minVal = min({left.minVal, right.minVal, root->val});
	t.maxVal = max({left.maxVal, right.maxVal, root->val});

	return t;

}

bool isBSTRange(TreeNode* root, long long lb, long long ub) {

	if (root == NULL) {
		return true;
	}

	return root->val > lb and root->val < ub and
	       isBSTRange(root->left, lb, root->val) and
	       isBSTRange(root->right, root->val, ub);

}

int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	isBST(root) ? cout << "true" << endl : cout << "false" << endl;

	isBSTEfficient(root).bst ? cout << "true" << endl : cout << "false" << endl;

	long long lb = (long long)INT_MIN - 1; // or LLONG_MIN
	long long ub = (long long)INT_MAX + 1; // or LLONG_MAX

	isBSTRange(root, lb, ub) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}