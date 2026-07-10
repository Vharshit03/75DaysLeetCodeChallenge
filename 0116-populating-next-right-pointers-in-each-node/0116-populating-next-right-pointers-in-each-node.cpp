/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connectNode(Node* leftNode,Node* rightNode){

        if(!leftNode && !rightNode)
        return;

        leftNode->next = rightNode;

        connectNode(leftNode->left,leftNode->right);
        connectNode(rightNode->left,rightNode->right);

        while(leftNode->right){
            leftNode = leftNode->right;
            rightNode = rightNode->left;

            leftNode->next = rightNode;
        }
    }
    Node* connect(Node* root) {
        
        if(!root)
        return NULL;

        connectNode(root->left,root->right);

        return root;
    }
};