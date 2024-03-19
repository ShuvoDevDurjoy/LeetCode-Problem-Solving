struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* swap(ListNode *head )
{
    
    ListNode *node = head  ;
    if(head->next )
    {
        node = head->next ; 
    }
    else {
        return head ; 
    }
    ListNode *node1 = head ; 
    while(head->next){ 
        node1->next = head->next   ; 
        ListNode *temp = head->next ; 
        head->next = temp->next ; 
        temp->next = head ; 
        node1 = head ; 
        head = (head->next)?head->next : head ; 
    }
    return node ; 
}
