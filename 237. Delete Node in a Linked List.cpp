/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //next為要刪除節點的下一個節點
        ListNode *next=node->next;
        //把要刪除的節點值,改成跟下一個節點值一樣
        node->val=next->val;
        //把要刪除的節點,指向下下一個節點
        node->next=next->next;
        //刪除next(也就是重複的節點)
        delete next;
    }
};