#include<iostream>
#include<unordered_map>

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

class TreeNodeHash {

public:
    size_t operator()(const TreeNode* node) const {
        if (node == nullptr) {
            return 0;  // Hash value for nullptr
        }

        // Simple hash function combining hash values of val, left, and right

        hash<int> intHashFn;

        size_t valHash = intHashFn(node->val);

        hash<TreeNode*> leftHashFn;
        size_t leftHash = leftHashFn(node->left);

        hash<TreeNode*> rightHashFn;
        size_t rightHash = rightHashFn(node->right);

        // Combine hash values using XOR (^)
        return valHash ^ leftHash ^ rightHash;
    }
};


// recursive implementation

int helper(TreeNode* root) {

    // base case

    if (root == NULL) {
        return 0;
    }

    // recursive case

    // decide for the root node

    // 1. don't rob the root node

    int dontRobRoot = helper(root->left) + helper(root->right);

    // 2. rob the root node

    int robRoot = root->val;
    if (root->left != NULL)  robRoot += helper(root->left->left)  + helper(root->left->right);
    if (root->right != NULL) robRoot += helper(root->right->left) + helper(root->right->right);

    return max(dontRobRoot, robRoot);

}

// recursive implementation

int helperTopDown(TreeNode* root, unordered_map<TreeNode*, int, TreeNodeHash>& dp) {

    // lookup
    if (dp.find(root) != dp.end()) {
        return dp[root];
    }

    // base case

    if (root == NULL) {
        return dp[root] = 0; // or dp.insert({root, 0}) then return dp[root]
    }

    // recursive case

    // decide for the root node

    // 1. don't rob the root node

    int dontRobRoot = helperTopDown(root->left, dp) + helperTopDown(root->right, dp);

    // 2. rob the root node

    int robRoot = root->val;
    if (root->left != NULL)  robRoot += helperTopDown(root->left->left, dp)  + helperTopDown(root->left->right, dp);
    if (root->right != NULL) robRoot += helperTopDown(root->right->left, dp) + helperTopDown(root->right->right, dp);

    return dp[root] = max(dontRobRoot, robRoot);

}

int rob(TreeNode* root) {

    // return helper(root);

    unordered_map<TreeNode*, int, TreeNodeHash> dp;

    return helperTopDown(root, dp);

}

int main() {

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout << rob(root) << endl;

    // TreeNode* root = new TreeNode(3);

    // root->left = new TreeNode(4);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);

    // root->right = new TreeNode(5);
    // root->right->right = new TreeNode(1);

    // cout << rob(root) << endl;

    return 0;
}