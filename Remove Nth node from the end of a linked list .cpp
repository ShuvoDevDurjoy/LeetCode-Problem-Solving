ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node = head ; 
    int size = 0 ; 
    while(node!=NULL){
        node = node->next ; 
        ++size ; 
    } 
    size= size - n ; 
    if(size == 0){
        head = head->next ; 
    }
    else{
        node = head ; 
        ListNode *track = node ; 
    for(int i = 0 ; i < size ; ++ i){
        track = node ; 
        node = node->next ; 
    }
    track->next = node->next; 
    }
    return head ; 
  } 
