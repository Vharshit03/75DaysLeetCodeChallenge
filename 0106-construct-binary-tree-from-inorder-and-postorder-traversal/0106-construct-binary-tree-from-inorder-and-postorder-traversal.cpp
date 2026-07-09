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
    TreeNode* treeBuild(vector<int>& inorder,int inStart,int inEnd, vector<int>& postorder,int postStart,int postEnd, unordered_map<int,int> &inMap){

        if(inStart > inEnd || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int RtLen = inEnd-inRoot;

        root->left = treeBuild(inorder,inStart,inRoot-1,postorder,postStart,postEnd-RtLen-1,inMap);

        root->right = treeBuild(inorder,inRoot+1,inEnd,postorder,postEnd-RtLen,postEnd-1,inMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if(inorder.empty() || postorder.empty() || inorder.size()!=postorder.size())
        return nullptr;
        
        unordered_map<int,int> inMap;

        for(int i=0;i<inorder.size(); i++)
        inMap[inorder[i]] = i;

        TreeNode* root = treeBuild(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inMap);

        return root;
    }
};