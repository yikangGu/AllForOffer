class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> temp;
        vector<int> ret;
        while(head!=NULL) {
            temp.push(head->val);
            head = head->next;
        }
        int i;
        while(!temp.empty()){
            i = temp.top();
            temp.pop();
            ret.push_back(i);
        }
        return ret;
    }

    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL || pHead->next->next == NULL){
            return NULL;
        }
        ListNode *slow = pHead->next;
        ListNode *fast = pHead->next->next;
        while( slow != fast)
        {
            if(fast->next==NULL || fast->next->next==NULL){
                return NULL;
            } else {
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        fast = pHead;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};


