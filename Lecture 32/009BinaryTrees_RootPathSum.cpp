#include<iostream>
#include<vector>

using namespace std;

class TreeNode {

public :

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}

};

// int countPaths(TreeNode* root, int targetSum) {

// 	// base case

// 	if (root == NULL) {
// 		return 0;
// 	}

// 	// recursive case

// 	// 1. recursively, count the no. of paths starting from the root in the leftSubtree whose sum is equal to targetSum-root->val

// 	int x = countPaths(root->left, targetSum - root->val);

// 	// 2. recursively, count the no. of paths starting from the root in the rightSubtree whose sum is equal to targetSum-root->val

// 	int y = countPaths(root->right, targetSum - root->val);

// 	return x + y + (root->val == targetSum ? 1 : 0);

// }

int countPaths(TreeNode* root, int targetSum) {

	// base case

	if (root == NULL) {
		return 0;
	}

	// recursive case

	// count no. of paths in the tree starting from the root whose sum is equal to targetSum

	int count = 0;

	// 1. recursively, count the no. of paths starting from the root in the leftSubtree whose sum is equal to targetSum-root->val

	count += countPaths(root->left, targetSum - root->val);

	// 2. recursively, count the no. of paths starting from the root in the rightSubtree whose sum is equal to targetSum-root->val

	count += countPaths(root->right, targetSum - root->val);

	if (root->val == targetSum) count++;

	return count;

}


int main() {

	TreeNode* root = NULL;

	root = new TreeNode(2);

	root->left = new TreeNode(7);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(1);
	root->left->left->right = new TreeNode(8);
	root->left->right = new TreeNode(3);

	root->right = new TreeNode(6);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);

	int targetSum = 12;

	// root = new TreeNode(4);

	// root->left = new TreeNode(7);
	// root->left->left = new TreeNode(3);
	// root->left->left->left = new TreeNode(1);
	// root->left->left->right = new TreeNode(8);
	// root->left->right = new TreeNode(3);

	// root->right = new TreeNode(6);
	// root->right->left = new TreeNode(4);
	// root->right->right = new TreeNode(5);

	// int targetSum = 4;

	cout << countPaths(root, targetSum) << endl;

	return 0;
}