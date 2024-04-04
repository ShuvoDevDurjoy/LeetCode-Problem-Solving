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
    ListNode* deleteMiddle(ListNode* head) {

        int size = 0 ; 
        ListNode *temp = head ; 
        while(temp){
            temp = temp->next ; 
            ++size ; 
        }

        size = size/2 ; 
        if(size==0) {
            head = NULL ; 
            return head ; 
        }

        temp = NULL ; 
        ListNode *temp1 = head ; 

        for(int i = 0 ; i < size ; ++i)
        {
            temp = temp1 ; 
            temp1 = temp1->next ; 
        }

        temp->next = temp1->next ; 
    return head ; 
        
    }

};
