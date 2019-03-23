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
        if(head == NULL)
            return NULL;
        ListNode* oddNode = head;
        ListNode* evenNode = head->next;
        ListNode* evenHeadNode = head->next;
        
        while(evenNode != NULL && evenNode->next != NULL)
        {
            oddNode->next = oddNode->next->next;
            evenNode->next = evenNode->next->next;
            oddNode = oddNode->next;
            evenNode = evenNode->next;
        }
        
        oddNode->next = evenHeadNode;
        return head;
    }
};