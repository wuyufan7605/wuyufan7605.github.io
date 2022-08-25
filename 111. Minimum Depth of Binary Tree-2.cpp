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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;  //如果沒有root,就回傳0
        queue<TreeNode*> Q; //建一個Queue叫Q
        Q.push(root);       //把root push進Queue
        int height=0;       //一開始把樹高設成0
        while(!Q.empty()){
            height++;
            int k=Q.size();  //設k為Queue的元素個數
            for(int j=0;j<k;j++){
                TreeNode* rt=Q.front(); //rt為每次Queue的front,(就是要pop出去的節點)
                //把下一層的左右子點push進去
                if(rt->left) Q.push(rt->left);
                if(rt->right) Q.push(rt->right);
                //把上一層的root pop出去
                Q.pop();
                //如果下一層沒有左右子點,就直接回傳樹高
                if(rt->left==NULL && rt->right==NULL) return height;
            }
        }
        return 0;//為了compiler才打的
        
    }
};