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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        //base case: agar array khali ho gaya toh tree nahi ban sakta (return NULL)
        if(preorder.size()==0 || inorder.size()==0){
            return NULL;
        }

        //PREODER KA ZERO SABSE PEHLE WALAA ROOT HAI
        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);

        //step 2: inorder mein is boss ki kursi position dhondo
        int mid = 0;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==rootValue){
                mid = i;//boss mil gaya
                break;
            }
        }


        //step 3: array ko left aur right team mein slice kardenge
        vector<int>leftInorder(inorder.begin(),inorder.begin()+mid);

        vector<int>rightInorder(inorder.begin()+mid+1,inorder.end());

        //preorder ko katna 
        //pehla banda  index 0 toh boss tha,index 1 se shuru karenge
        vector<int>leftPreorder(preorder.begin()+1,preorder.begin()+1+mid);

        vector<int>rightPreorder(preorder.begin()+1+mid,preorder.end());

        //step4: bacchon ko unki team de do aur apna-apna subtree bananane ko bolo
        root->left = buildTree(leftPreorder,leftInorder);

        root->right = buildTree(rightPreorder,rightInorder);

        return root;
    }
};
