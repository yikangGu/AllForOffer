class Solution {
public:
  ListNode* EntryNodeOfLoop(ListNode* pHead)
  {
    if(pHead == nullptr)
        return NULL;
    ListNode* p1;
    ListNode* p2;
    p1 = pHead;
    p2 = pHead;

    while(1){
      //update with different speed
      if(p1->next == nullptr)
        return NULL;
      else
        p1 = p1->next;
    
      if(p2->next == nullptr || p2->next->next == nullptr)
        return NULL;
      else
        p2 = p2->next->next;
      //check if they meet
      if(p1 == p2)
        break;
    }
    p1 = pHead;
    while(1){
      if(p1 == p2)
        return p1;
      p1 = p1->next;
      p2 = p2->next;
    }
  }
};
