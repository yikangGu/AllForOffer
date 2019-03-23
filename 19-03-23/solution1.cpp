i/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a = headA, b = headB;
        int a_len = 0, b_len = 0;
        while(a!=NULL){
            a_len += 1;
            a = a->next;
        }
        while(b!=NULL){
            b_len += 1;
            b = b->next;
        }
        ListNode *start,*other;
        if(a_len > b_len){
            start = headA;
            other = headB;
        } else {
            start = headB;
            other = headA;
        }
        for(int i=0; i < abs(a_len-b_len); i++){
            start = start->next;
        }
        while(start!=NULL){
            if(start == other){
                return start;
            }
            start = start->next;
            other = other->next;
        }
        return NULL;
    }
};
