 //定義節點的類別
 //有:值 左子點 右子點
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

  struct TreeNode* invertTree(struct TreeNode* root){
    //設定一個條件,避免一直跑不停
    if(root==NULL){
        return NULL;
    }
    //結構指標
    //最後是星號結尾的用->
    //把root左子點的左右子點交換
    //把root右子點的左右子點交換
    invertTree(root->left);
    invertTree(root->right);
    //最後再將root的左右子點交換
    struct TreeNode* temp=root->left;
    root->left=root->right;
    root->right=temp;
    
    
    return root;
}