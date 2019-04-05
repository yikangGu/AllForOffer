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
        if(pHead == nullptr) return pHead;
        ListNode* pBegin = pHead;
        ListNode* prev = nullptr;
        while(pBegin && pBegin->next){
            if(pBegin->val != pBegin->next->val){
                prev = pBegin;
                pBegin = pBegin->next;
            }else{
                int repeat_val = pBegin->val;
                ListNode* temp = pBegin;
                while(temp && temp->val == repeat_val){
                    temp = temp->next;
                }
                if(prev != nullptr){
                    prev->next = temp;
                    pBegin = temp;
                }else{
                    pBegin = temp;
                    pHead = temp;
                }
            }
            
        }
        return pHead;
    }
};
