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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //為避免內存洩漏,所以另外建一個dummy,指向一個node=0
        ListNode dummy(0);
        //cur為一個指針,指向dummy
        ListNode* cur=&dummy;
        
        int carry=0;
        int v1,v2;
        int val;
        //當l1,l2,sum不為空時,就做循環
        while(l1||l2||carry){
            v1=l1?l1->val : 0;
            v2=l2?l2->val : 0;
            //算現在數字的val及carry(由有沒有進位)
            val=v1+v2+carry;
            carry=val/10;
            val=val%10;
            cur->next=new ListNode(val);
            //往右邊數字移動並計算
            cur=cur->next;
            l1=l1?l1->next : nullptr;
            l2=l2?l2->next : nullptr;
        }
        
        return dummy.next;
    }
};