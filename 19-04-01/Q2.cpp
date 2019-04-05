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
        if(!pHead1 || !pHead2) return nullptr;
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        while(pHead1){
            s1.push(pHead1);
            pHead1 = pHead1->next;
        }
        while(pHead2){
            s2.push(pHead2);
            pHead2 = pHead2->next;
        }
        ListNode* res = nullptr;
        while(!s1.empty() && !s2.empty() && s1.top() == s2.top()){
            res = s1.top();
            s1.pop();
            s2.pop();
        }
        return res;
    }
};
