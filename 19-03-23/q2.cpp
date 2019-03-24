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

    ListNode* oddEvenList(ListNode* head) {
        ListNode* front = head;
        ListNode* back = head;
        int id = 1;
        while(back->next != nullptr){
            id++;
            back = back->next;
            if(!(id%2)){
                ListNode* tmp0 = back->next;
                back->next = back->next->next;
                ListNode* tmp1 = front->next;
                front->next = tmp0;
                tmp0->next = tmp1;
                front = front->next;
                id++;
            }
        }
        return head;
    }
};
