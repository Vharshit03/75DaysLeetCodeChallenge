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
    TreeNode* flatTree(TreeNode* root){

        if(!root)
        return root;
        
        if(!root->left && !root->right)
        return root;

        flatTree(root->right);

        if(root->left){
        TreeNode* left = flatTree(root->left);

        TreeNode* leftRMost = left;

        while(leftRMost->right!=NULL)
        leftRMost = leftRMost->right;

        leftRMost->right = root->right;
        root->right = left;

        root->left = NULL;

        }

        return root;

    }
    void flatten(TreeNode* root) {

        flatTree(root);
    }
};