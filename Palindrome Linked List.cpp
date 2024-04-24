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
    bool isPalindrome(ListNode* head) {
        vector<int> lists ; 
   ListNode *temp = head ; 
   while(temp)
   {
      lists.push_back(temp->val) ; 
      temp = temp->next ; 
   }

   int left = 0 ; 
   int right = lists.size()-1 ; 
   while(left<right)
   {
      if(lists[left]!=lists[right])
      {
         return false ; 
      }
      left++ ; 
      right-- ;
   }
   return true ;
    }
};
