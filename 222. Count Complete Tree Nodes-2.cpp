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
     int countNodes(TreeNode* root) {
         //如果為空,return 0
        if(root==nullptr) return 0;
        //l,r分別為左邊及右邊的高度
        int l=height(root->left);
        int r=height(root->right);
        //如果左右子樹高度依樣
         if(l==r)
            //表左邊為Complete binary tree回傳:右邊子樹高度+2^l-1
             return (1<<l)+countNodes(root->right);
         else
            //2^(l-1)(表示右邊子樹的節點數,包含root)+左邊子樹高度
             return (1<<(l-1))+countNodes(root->left);
    }
private:
    //計算子樹高度之副程式
    int height(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+height(root->left);
    }
   
};