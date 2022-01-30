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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //建立一個新的點dummy
        ListNode* dummy=new ListNode();
        //curr指向dummy
        ListNode* curr=dummy;
        //若list1和list2皆不為空
        while(list1 && list2){
            //如果list1的值<=list2的值
            if(list1->val<=list2->val){
                //curr->next為list1和list2中,值小的數
                curr->next=list1;
                //list1已比較過,往下一個值移動
                list1=list1->next;
            }
            //如果list2的值>list1的值
            else{
                //curr->next為list1和list2中,值小的數
                curr->next=list2;
                //list2已比較過,往下一個值移動
                list2=list2->next;
            }
            //curr指向下一個值
            curr=curr->next;
        }
        //到最後會有值剩下來的情況
        //如果list1都比過了
        if(!list1){
            //指向list2剩下的值
            curr->next=list2;
        }
        //如果list2都比過了
        else if(!list2){
            //指向list1剩下的值
            curr->next=list1;
        }
        return dummy->next;
    }
};