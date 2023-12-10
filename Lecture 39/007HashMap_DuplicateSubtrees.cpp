/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    unordered_map<string, TreeNode*> treeReprMap;
    set<TreeNode*> outSet;

    string dfs(TreeNode* root) {

        // base case

        if (root == NULL) {

            return "X";

        }

        // recursive case

        string leftRepr = dfs(root->left);
        string rightRepr = dfs(root->right);

        string rootRepr = to_string(root->val) + " " + leftRepr + " " + rightRepr;

        if (treeReprMap.find(rootRepr) != treeReprMap.end()) {

            // you've seen rootRepr i.e. the subTree rooted at the given root previously

            outSet.insert(treeReprMap[rootRepr]); // or outSet.insert(root);

        } else {

            treeReprMap[rootRepr] = root;

        }

        return rootRepr;

    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);

//         vector<TreeNode*> outVector;
//         for(TreeNode* duplicateRoot : outSet) {
//             outVector.push_back(duplicateRoot);
//         }
//         return outVector;

        return vector<TreeNode*>(outSet.begin(), outSet.end());
    }
};