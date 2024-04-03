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
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = head ; 
        vector<int> nums ; 
        while(temp!=NULL){
            nums.push_back(temp->val) ; 
            temp = temp->next ; 
        }
        temp = head ; 

        for(int i = nums.size()-1 ; i >=0 ; --i){
            temp->val = nums[i] ; 
            temp = temp->next ; 
        }
        return head ; 
    }
};
