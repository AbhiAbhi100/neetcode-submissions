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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMaxPath(root,maxi);   
        return maxi;
    }

private:
    int findMaxPath(TreeNode* node,int& maxi){
        if(node==NULL){
            return 0;
        }

        //left aur right subtrees se max path sum lagao 
        //agar negative hai toh 0 consider karo(ignore the branch)

        int leftSum = max(0,findMaxPath(node->left,maxi));
        int rightSum = max(0,findMaxPath(node->right,maxi));

        maxi = max(maxi,leftSum+rightSum+node->val);

        //parent ko batana hai ki "meri taraf aaoge toh kitna max fayda me"
        //rahoge--> straight line maintain karne ke liye dono me sirf
        //best rasta bhejna padega

        return node->val+max(leftSum,rightSum);


    }
};
