//建立一個函式
void dfs(int depth,TreeNode* root,vector<vector<int>>& result){
    //設定一個條件,避免函式一直在跑
    if (root == nullptr){
        return;
    }
    //若第幾層跟result的大小一樣,就創一個空陣列  
    if(depth == result.size()){
        result.push_back({});
    }
    //陣列[層數] 
    //第幾層的數字,就會放在相對應的陣列中
    result[depth].push_back(root->val);
    
    //重複做左子樹
    //重複做右子樹
    //因為root設為指標,所以用->
    dfs(depth+1,root->left,result);
    dfs(depth+1,root->right,result);
}

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        dfs(0,root,result);
        //由於上一行,是由上到下排序(top-down)
        //這邊把它改為由下到上(buttom-up)
        reverse(begin(result),end(result));
        return result;
    }
};