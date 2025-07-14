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
    int getDecimalValue(ListNode* head) {
        stringstream str;
        while(head){
            str<<head->val;
            head = head->next;
        }
        bitset<32> bits(str.str());
        long result = bits.to_ulong();
        return result;
    }
};
