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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#,";

        //Pre-order:root->left->right
        string result = to_string(root->val)+",";
        result+=serialize(root->left);
        result+=serialize(root->right);

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        //Stringstream string se data ko sequentiallu read karne me help 
        //karta hai
        stringstream s(data);
        return buildTree(s);
    }

private:

    //Helper function tree builld karne ke lie hai
    TreeNode* buildTree(stringstream& s){
        string str;

        //comma (,) aane tak read karenge aur 'str' me store karenge
        getline(s,str,',');

        if(str == "#"){
            return NULL;
        }

        //Root node banao string ko integer me covert karke
        TreeNode* root = new TreeNode(stoi(str));

        //Recursivly left and right subtree build karenge
        root->left = buildTree(s);
        root->right = buildTree(s);

        return root;
    }
};
