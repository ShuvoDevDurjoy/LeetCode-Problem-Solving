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
    ListNode* deleteDuplicates(ListNode* head){
    if(!head){
        return head ; 
    }
    ListNode *temp = head ; 
    ListNode *temp2  = head ; 
    ListNode *track = head->next ;  ; 
    while(track){
        if(temp2->val == track->val ){
            temp->next = track->next  ; 
            temp2 = track ; 
            track = track->next ; 
            continue ; 
        } 
        else {
            temp->next = track ; 
            temp = temp->next ; 
            temp2 = track  ; 
            track = track->next ; 
        }
    }
    return head ; 

}
};
