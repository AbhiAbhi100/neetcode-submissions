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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        //Base case: agar koi rasta nahi hai
        if(root==NULL){
            return NULL;
        }

        //Post-order traversal: Pehle left,phir right
        root->left = removeLeafNodes(root->left,target);
        root->right = removeLeafNodes(root->right,target);

        //Root (parent) ki bari ye neeche bhi aaise hi hoga
        //kya ab yeh leaf node ban gaya hai AND iski value target ke barabar hai
        if(root->left == NULL && root->right == NULL && root->val==target){
            return NULL;
        }

        return root;
    }
};