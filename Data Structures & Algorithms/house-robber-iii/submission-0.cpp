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
    int rob(TreeNode* root) {
       // Helper function ek pair return karega
       //pair.first = agar root ko loota toh max money
       //pair.second = agar root ko NAHI loota toh max money

       pair<int,int>result = robHelper(root);

       //final answer dono option mein se max hoga
       return max(result.first,result.second);
    }

private:
    pair<int,int>robHelper(TreeNode* node){
        if(node==NULL){
            return {0,0};
        }

        //left aur right subtree se best possible choices le aao
        pair<int,int>leftChoices = robHelper(node->left);
        pair<int,int>rightChoices = robHelper(node->right);

        //option1:is node ko loot rhe hain toh
        //toh hum left aur right bacchon ko nahi loot sakte(unka .second use karene hum log)
        int robThis = node->val + leftChoices.second+rightChoices.second;

        //is node ko nahi loot rhe hain 
        //ab hamari marzi hai bacho ko lootna hai ya nahi ,jo max de wahi chaiye
        int dontRobThis = max(leftChoices.first,leftChoices.second)+max(rightChoices.first,rightChoices.second);

        return {robThis,dontRobThis};
        
    }
};