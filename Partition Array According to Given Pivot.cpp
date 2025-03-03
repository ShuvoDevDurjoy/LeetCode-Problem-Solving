class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> smaller;
        queue<int> equal;
        queue<int> larger;

        vector<int> result;

        for(auto &a: nums){
            if(a==pivot){
                equal.push(a);
            }
            else if(a<pivot){
                smaller.push(a);
            }
            else{
                larger.push(a);
            }
        }

        while(!smaller.empty()){
            result.push_back(smaller.front());
            smaller.pop();
        }

        while(!equal.empty()){
            result.push_back(equal.front());
            equal.pop();
        }

        while(!larger.empty()){
            result.push_back(larger.front());
            larger.pop();
        }

        return result;
    }
};
