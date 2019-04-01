/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* cur1 = pHead1;
        while(cur1 != NULL)
        {
            ListNode* cur2 = pHead2;
            while(cur2 != NULL)
            {
                if(cur1 == cur2)
                    return cur1;
                else
                    cur2 = cur2->next;
            }
            cur1 = cur1->next;
        }
        return NULL;
    }
};