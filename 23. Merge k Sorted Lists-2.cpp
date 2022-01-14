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
        return merge(lists,0,lists.size()-1);
    }
private:
    ListNode* merge(vector<ListNode*>& lists,int l,int r){
        //l>r的話就沒有元素了,返回空的指針
        if(l>r) return nullptr;
        //表只有一個list,返回唯一的list
        if(l==r) return lists[l];
        //若只有兩個lists,就合併兩個lists
        if(l+1==r) return mergeTwoLists(lists[l],lists[r]);
        //取中間list的index
        int m=l+(r-l)/2;
        //把左邊的lists合併
        auto l1=merge(lists,l,m);
        //把右邊的lists合併
        auto l2=merge(lists,m+1,r);
        //把左右兩個lists再合併,並回傳
        return mergeTwoLists(l1,l2);
    }
    
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        ListNode dummy(0);
        ListNode* tail=&dummy;
        while(l1&&l2){
            if(l1->val>l2->val) swap(l1,l2);
            //tail和l1同時往後移一格
            tail->next=l1;
            l1=l1->next;
            tail=tail->next;
        }
        //把tail->next指向剩下的部分
        tail->next=l1?l1:l2;
        return dummy.next;
    }
};