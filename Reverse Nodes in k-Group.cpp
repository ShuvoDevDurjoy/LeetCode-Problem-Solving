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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* prev = head ;
        ListNode* next = prev ; 
        ListNode* cur = head ;
        ListNode* temp = head ; 
        int index = 1 ; 
        ListNode* start = head ; 
        ListNode* p = nullptr ; 
        ListNode* returning = nullptr ; 
        while(cur!=nullptr){
            if(index==1){ 
                p = start ;
                start = cur;  
            }
            if(index==k){
                if(returning==nullptr){
                    returning = cur ; 
                }
                next = cur->next ; 
                cur->next = prev ; 
                if(p==nullptr){
                    p = start ; 
                } 
                else{
                    p->next = cur ; 
                    p = start ; 
                }
                prev = next ; 
                cur = next ; 
                index = 0 ; 
            }
            else{ 
                
                next = cur->next ; 
                cur->next = prev ; 
                if(p){
                    p->next = cur ; 
                }
                prev = cur ; 
                cur = next ; 
            }
            index++ ; 
        }
        start->next = nullptr ; 
        start->next = nullptr;
        start = p->next ; 
        if(!start) return returning ; 
        else{
            cur = start->next ; 
            start->next = nullptr ; 
            while(cur){
                next = cur->next ; 
                cur->next = start ; 
                p->next = cur ; 
                start = cur ; 
                cur = next ; 
            }
        }
        return returning;
    }
};
