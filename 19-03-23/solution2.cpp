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
        if(!(head && head->next)){
            return head;
        }
        auto odd = head, even = head->next, link = head->next, temp = head;
        while(odd){
            odd->next = odd->next ? odd->next->next : NULL;
            temp = odd;
            odd = odd->next;
            if(even) {
            even->next = even->next ? even->next->next : NULL;
            even = even->next;
            }
        }
        temp->next = link;
        return head;
    }
};
