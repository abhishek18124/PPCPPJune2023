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

int numCameras = 0; // to track the min. no. of cameras required to cover/monitor all the nodes

int helper(TreeNode* root) {

	// base case

	if (root == NULL) {

		return 1;

	}

	// recursive case

	int leftStatus = helper(root->left);
	int rightStatus = helper(root->right);

	// decide if you want install a camera at the root

	if (leftStatus == 0 || rightStatus == 0) {

		// install a camera at the root node

		numCameras++;
		return 2;

	}

	// do not install camera at the root node

	return leftStatus == 2 || rightStatus == 2 ? 1 : 0;

}

int minCameraCover(TreeNode* root) {

	int rootStatus = helper(root);
	if (rootStatus == 0) {
		numCameras++;
	}

	return numCameras;

}

int main() {

	TreeNode* root = NULL;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->left->left = new TreeNode(0);
	// root->left->left->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->right = new TreeNode(0);

	// root->right = new TreeNode(0);
	// root->right->left = new TreeNode(0);
	// root->right->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	TreeNode* root1 = new TreeNode(0);

	root = new TreeNode(0);

	root->left = new TreeNode(0);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(0);

	root->right = new TreeNode(0);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(0);

	root1->left = root;

	cout << minCameraCover(root1) << endl;


	return 0;
}