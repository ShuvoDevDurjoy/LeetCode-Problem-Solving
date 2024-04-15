/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int listAsize = 0 ; 
        int listBsize = 0 ; 
        ListNode *tempA = headA ; 
        ListNode *tempB = headB ; 
        while(tempA){
            ++listAsize ; 
            tempA = tempA->next ; 
        }

        while(tempB){
            ++listBsize ; 
            tempB = tempB->next ; 
        }

        tempA = headA ; 
        tempB = headB ; 
        while(listAsize>listBsize){
            tempA = tempA->next ; 
            listAsize-- ; 
        }

        while(listBsize>listAsize){
            tempB = tempB->next ; 
            listBsize-- ; 
        }
        ListNode *foundNode = NULL ;
        bool found = false ;  
        while(tempA && tempB){
            if(tempA==tempB)
            {
                if(found==false )
                {found = true ; foundNode = tempA ; }
            }
            else {
                found = false ; 
            }

            tempA = tempA->next ; 
            tempB = tempB->next ; 
        }

        return foundNode ; 
    }
};
