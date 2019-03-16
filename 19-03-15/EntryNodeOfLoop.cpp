class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* quick = pHead;
        ListNode* slow = pHead;
        
        while(quick != NULL && quick->next != NULL)
        {
            slow = slow->next;
            quick = quick->next->next;
            if(quick == slow)
            {
                quick = pHead;
                
                while(quick != slow)
                {
                    quick = quick->next;
                    slow = slow->next;
                }
                return quick;
            }
        }
        return NULL;
    }
};