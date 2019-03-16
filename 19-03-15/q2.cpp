class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
      vector<int> result;
      stack<int> tmp;
      if(head == nullptr)
          return result;
      ListNode* ptr;
      ptr = head;
      while(ptr != nullptr){
          tmp.push(ptr->val);
          ptr = ptr->next;
      }
      while(!tmp.empty()){
          result.emplace_back(tmp.top());
          tmp.pop();
      }
      return result;
    }
};
