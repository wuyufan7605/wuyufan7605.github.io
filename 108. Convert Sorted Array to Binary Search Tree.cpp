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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums,0,nums.size()-1);
    }
private:
    TreeNode* buildBST(const vector<int>& nums,int l,int r){
        if(l>r) return nullptr;
        //找出中間值
        int m=l+(r-l)/2;
        //把中間值當root
        TreeNode* root=new TreeNode(nums[m]);
        //左邊繼續找root
        root->left=buildBST(nums,l,m-1);
        //右邊繼續找root
        root->right=buildBST(nums,m+1,r);
        return root;
    }
};