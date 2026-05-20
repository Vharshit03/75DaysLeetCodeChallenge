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
    void PreOrder(TreeNode* root,vector<int>&pre){

        if(!root)
        return;

        pre.push_back(root->val);
        PreOrder(root->left,pre);
        PreOrder(root->right,pre);
    }
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int>ans;

        PreOrder(root,ans);

        return ans;
    }
};