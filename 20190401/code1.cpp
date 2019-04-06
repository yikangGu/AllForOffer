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
        if(pHead== nullptr) return nullptr;
        ListNode*pOut =  pHead;
        ListNode*pNode =  pHead;
        ListNode*pBef =  nullptr;
        while(pNode!= nullptr)
        {
             ListNode*pNext =  pNode->next;
            if(pNext!=nullptr && pNext->val == pNode->val)
            {
                while(pNext!= nullptr && pNext->val== pNode->val)
                    pNext= pNext->next;
                if(pBef!= nullptr)
                    pBef->next = pNext;
                if(pBef == nullptr)
                    pOut = pNext;
                if(pNext!=nullptr &&pNext->next!= nullptr && pNext->next->val!= pNext->val)
                    pBef = pNext->next;
                pNode = pNext;
            }
            else
            {
                pBef = pNode;
                pNode = pNode->next;
            }


        }
        return pOut;

    }
};
