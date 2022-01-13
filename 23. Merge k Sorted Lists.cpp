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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //建一個點:dummy head,這樣最後返回的時候比較簡單
        //值任意值都可以
        ListNode dummy(0);
        //把tail指向dummy head
        ListNode *tail=&dummy;
        
        //auto會根據初始化表達式自動判斷被聲明的type 
        //因為想要min-heap,也就是小的放前面
        //所以要寫反過來的(預設為max-heap)
        auto comp=[](ListNode* a,ListNode* b){return a->val>b->val;};
        priority_queue <ListNode*,vector<ListNode*>, decltype(comp)>q(comp);
        
        for(ListNode* list:lists){
            //把練表的頭加到priority_queue中
            if(list){
                q.push(list);
            }
        }
        
        //如果不為空,就拿出最小的元素
        while(!q.empty()){
            tail->next=q.top(); q.pop();
            tail=tail->next;
            if(tail->next) q.push(tail->next);
        }
        return dummy.next;
    }
};