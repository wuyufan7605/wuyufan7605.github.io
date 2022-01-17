/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        //建一個vector
        vector <int>result;
        //追蹤children
        travel(root,result);
        //回傳結果
        return result;
    }
private:
    void travel(Node* root,vector<int>& result){
        //如果root為空,就return
        if(root==nullptr){
            return;
        }
        //把root的值push進去result
        result.push_back(root->val);
        //對每個child做recursive(travel函式)
        for(Node* child : root->children){
            travel(child,result);
        }
    }
        
};