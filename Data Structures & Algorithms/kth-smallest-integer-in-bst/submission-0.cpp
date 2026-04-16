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
    int kthSmallest(TreeNode* root, int k) {
        

        vector<int>inorderArray;

        //pura inorder traversal karke array bhar do
        inorderHelper(root,inorderArray);

        return inorderArray[k-1];
    }

private:
    void inorderHelper(TreeNode* node,vector<int>& arr){
        if(node==NULL){
            return;
        }

        //Left->ROOT->RIGHT;
        inorderHelper(node->left,arr);
        arr.push_back(node->val);
        inorderHelper(node->right,arr);
    }
};
