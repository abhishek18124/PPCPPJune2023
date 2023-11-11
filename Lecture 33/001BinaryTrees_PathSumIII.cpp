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



int pathSum(TreeNode* root, int targetSum) {

	// base case

	if (root == NULL) {
		return 0;
	}

	// recursive case

	// 1. recursively, count the no. of paths in the leftSubtree whose sum is equal to targetSum

	int x = pathSum(root->left, targetSum);

	// 2. recursively, count the no. of paths in the rightSubtree whose sum is equal to targetSum

	int y = pathSum(root->right, targetSum);

	// 3. count the no. of paths starting from the root in the given tree whose sum is equal to targetSum

	int z = countPaths(root, targetSum);

	return x + y + z;

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(1);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->right = new TreeNode(1);

	int targetSum = 8;

	cout << pathSum(root, targetSum) << endl;

	return 0;
}