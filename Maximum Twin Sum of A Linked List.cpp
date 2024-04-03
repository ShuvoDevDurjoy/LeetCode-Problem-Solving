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
    int pairSum(ListNode* head) {
        ListNode *temp = head ; 
        vector<int> nums ; 
        while(temp){
            nums.push_back(temp->val) ; 
            temp = temp->next ; 
        }

        int left = 0 ;
        int right = nums.size()-1 ; 
        int max = 0 ; 
        while(left<right){
            if(nums[left]+nums[right]>max){
                max = nums[left]+nums[right] ; 
            }
            left++ ; 
            right-- ; 
        }
        return max ; 
    }
};
