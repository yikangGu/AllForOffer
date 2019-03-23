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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        int lenA = 0;
        int lenB = 0;
        ListNode *longNode = headA;
        ListNode *shortNode = headB;
        while (longNode) 
        {
            ++lenA;
            longNode = longNode->next;
        }
        while (shortNode) 
        {
            ++lenB;
            shortNode = shortNode->next;
        }
        int diff = lenA - lenB;
        longNode = headA;
        shortNode = headB;
        if (lenA < lenB) 
        {
            diff = -diff;
            longNode = headB;
            shortNode = headA;
        }
        for (int i = 0; i < diff; i++) 
            longNode = longNode->next;
        while (longNode && shortNode && longNode != shortNode) 
        {
            longNode = longNode->next;
            shortNode = shortNode->next;
        }
        return longNode;
    }
};