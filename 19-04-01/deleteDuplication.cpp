/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* pre = NULL;
        ListNode* follow = NULL;
        ListNode* current = pHead;
        while(current != NULL)
        {
            if(current->next != NULL && current->next->val == current->val)
            {
                follow = current->next;
                while(follow != NULL && follow->next != NULL && follow->next->val == current->val)
                {
                    follow = follow->next;
                }
                if(current == pHead)
                {
                    pHead = follow->next;
                }
                else
                {
                    pre->next = follow->next;
                }
                current = follow->next;
            }
            else
            {
                pre = current;
                current = current->next;
            }
        }
        return pHead;
    }
};