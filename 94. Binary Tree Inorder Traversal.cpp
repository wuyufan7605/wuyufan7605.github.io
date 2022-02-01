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
    vector<int> res;
    void inorder(TreeNode* root){
        //沒有root即return
        if(!root) return;
        //中序:左中右
        //先左邊
        inorder(root->left);
        //再中間
        res.push_back(root->val);
        //最後右邊
        inorder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        //如果沒有root
        if(root==NULL) return res;
        //如果有root
        inorder(root);
        return res;
    }
};