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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //如果兩個node都是null,代表兩個樹的節點都相同
        if(p==NULL&&q==NULL){
            return true;
        }
        
        //如果一個為null,一個不是null,那兩個也不相同
        if(p!=NULL&&q==NULL||p==NULL&&q!=NULL){
            return false;
        }
        
        //如果值不相同,便false
        if(p->val != q->val){
            return false;;
        }
        
        //遞迴看下一個level的點是否相同
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};