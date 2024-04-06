/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
       if(head==NULL) return  head ; 
        else if(head->next == NULL) return  head  ; 
        ListNode *tail = head ; 
        int size = 1 ; 
        while(tail->next!=NULL){
            tail = tail->next ; 
            ++size ; 
        }


        if(k>size) k = k%size ; 

        size = size - k ; 
        if(size==0) return head ; 
        ListNode *temp = head ;
        while(size>1){
            temp = temp->next ; 
            --size ; 
        }
        cout<<temp<<endl;
            tail->next = head ; 
        head = temp->next ; 
        temp->next = NULL ; 

        return head ; 
    }
};
