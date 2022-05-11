/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //如果head為空,或只有一個點
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode*cur=head;

        while(cur->next!=NULL){
            //如果下一個點重複
            if(cur->val==cur->next->val){
                //cur->next指向下一個點
                cur->next=cur->next->next;
            }else{
                //反之,不掠過,並繼續跑回圈,檢查後面的點
                cur=cur->next;
            }
        }
        return head;
    }
};