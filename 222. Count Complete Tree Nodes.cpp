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
        //若沒root 節點數為0
        if(root==nullptr) return 0;
        //使用遞歸 : 左子樹節點數+右子樹節點數+1(root)
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};