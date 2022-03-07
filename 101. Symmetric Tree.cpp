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
    bool isSymmetric(TreeNode* root) {
        //如果沒有root也是對稱
        if(!root)
            return true;
        //看左右子樹是否對稱
        return areMirror(root->left,root->right);
    }
    //副程式:看左右子樹是否對稱
    bool areMirror(TreeNode* t1,TreeNode* t2){
        //要有左右子點才行(不可其一為空)
        if(!t1||!t2){
            return(t1==t2);
        }
        //左右子點的值要一樣
        if(t1->val!=t2->val){
            return false;
        }
        //繼續往下層的子點檢查:是否對稱
        return (areMirror(t1->left,t2->right)&&areMirror(t1->right,t2->left));
    }
};
