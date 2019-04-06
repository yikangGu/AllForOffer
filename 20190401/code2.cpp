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
        ListNode* p1 = pHead1; 
        ListNode* p2 = pHead2;
        while(p1!= p2)
        {
            if(p1!=nullptr)
            {
                p1 = p1->next;
            }
            else
            {
                p1 = pHead2;
            }
            if(p2!=nullptr)
            {
                p2 = p2->next;
            }
            else
            {
                p2 = pHead1;
            }
            
        }
        return p1;
    }
};