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
    TreeNode* invertTree(TreeNode* root) {
        //base case: agar node NULL -> return 
        //Left subtree ko invert karo
        //Right subtree ko invert karo
        //dono ko swap kar do
        if(root==NULL) return NULL;

        //SWAP left and right
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        //recursive call
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
