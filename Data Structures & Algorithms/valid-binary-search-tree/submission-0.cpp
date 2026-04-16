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


    bool checkBST(TreeNode* node,long long min_val,long long max_val){

        if(node==nullptr){
            return true;
        }

        if(node->val<=min_val || node->val >= max_val){
            return false;
        }

        bool leftIsValid = checkBST(node->left,min_val,node->val);

        bool rightIsValid = checkBST(node->right,node->val,max_val);

        return leftIsValid && rightIsValid;
    }


    bool isValidBST(TreeNode* root) {
        
        return checkBST(root,LONG_MIN,LONG_MAX);
    }
};
