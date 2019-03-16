class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vals;
        ListNode* tailHead = NULL;
        ListNode* preNode = NULL;
        ListNode* pNode = head;
        
        while(pNode != NULL)
        {
            if(pNode->next == NULL) tailHead = pNode;
            
            ListNode* nxt = pNode->next;
            pNode->next = preNode;
            preNode = pNode;
            pNode = nxt;
        }
        
        while(tailHead != NULL)
        {
            vals.push_back(tailHead->val);
            tailHead = tailHead->next;
        }
        return vals;
    }
};