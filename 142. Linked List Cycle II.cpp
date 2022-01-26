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
    ListNode *detectCycle(ListNode *head) {
        bool isCycle=false;
        ListNode *s=head;
        ListNode *F=head;
        ListNode *s2;
        //只要head不為空,且head->next不為空,就持續跑回圈
        while(F!=NULL && F->next!=NULL){
            //s為慢指針,F為快指針
            s=s->next;
            F=F->next->next;
            //當快慢指針相遇
            if(s==F){
                //就設成有cycle
                isCycle=true;
                break;
            }
        }
        //如果有cycle
        if(isCycle){
            //s2指針指向head
            s2=head;
            //只要s2跟[cycle的起點]不同,就繼續跑回圈
            while(s!=s2){
                //兩個都同時向後移動,直到相遇
                s=s->next;
                s2=s2->next;
            }
            //s即為cycle的頭
            return s;
        }
        //如果上述都不符合,回傳null
        return NULL;
    }
};