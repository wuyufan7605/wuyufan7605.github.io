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
    //ans表示是否平衡
    bool ans;
    //這個函式用來確認是否平衡
    //會不斷遞回
    int checkBalance(TreeNode* root){
        if(!root) 
            return 0;
        if(!ans) //如果答案已經錯了且已經回傳
            return 0;
        //往左右子樹遞回
        int leftSubTree=checkBalance(root->left);
        int rightSubTree=checkBalance(root->right);
        if(abs(leftSubTree-rightSubTree)>1){
            ans=false;
        }
        //算每個點的高度
        return 1+max(leftSubTree,rightSubTree);
    }
    
    //這邊為主程式
    //一開始設有平衡
    //若不符合再改成false
    bool isBalanced(TreeNode* root){
        ans=true;
        int temp=checkBalance(root);
        return ans;
    }

};
