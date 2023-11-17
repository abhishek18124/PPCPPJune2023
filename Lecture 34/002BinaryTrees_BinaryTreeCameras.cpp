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

class Triple {
public :

	int numCameras;
	bool isCovered;
	bool hasCamera;

};

Triple helper(TreeNode* root) {

	Triple t;

	// base case

	if (root == NULL) {

		t.numCameras = 0;
		t.isCovered = true; // we don't want to install cameras at the leaf since we want to maximize coverage for each camera that we install
		t.hasCamera = false;

		return t;

	}

	// recursive case

	Triple left = helper(root->left);
	Triple right = helper(root->right);

	// if(left.isCovered == false || right.isCovered == false) {
	if (!left.isCovered || !right.isCovered) {
		// install a camera at the root node

		t.numCameras = left.numCameras + right.numCameras + 1;
		t.isCovered = true;
		t.hasCamera = true;

		return t;

	}

	// since left.isCovered == true and right.isCoverd == true

	// we will not install a camera at the root node

	t.numCameras = left.numCameras + right.numCameras;

	// t.isCovered = left.hasCamera == true || right.hasCamera == true ? true : false;
	t.isCovered = left.hasCamera || right.hasCamera ? true : false;

	t.hasCamera = false;

	return t;

}

int minCameraCover(TreeNode* root) {

	Triple t = helper(root);

	if (t.isCovered == false) {
		// you've install a camera at the root
		return t.numCameras + 1;
	}

	// you don't need to install camera at the root
	return t.numCameras;

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