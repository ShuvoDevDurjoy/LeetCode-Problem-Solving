class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        set<int> indexSet;
        for(int i =0; i < nums.size() - 1; ++i){
            pq.push({nums[i] + nums[i+1], i});
            indexSet.insert(i);
        }
        indexSet.insert(nums.size()-1);

        int count = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            if(indexSet.find(top.second) != indexSet.end()){
                int topNext = 0;
                auto itFirst = indexSet.lower_bound(top.second);
                auto it = indexSet.upper_bound(top.second);
                
                if(itFirst == indexSet.end()) continue;
                if(nums[top.second] > nums[*itFirst]) continue;
                if(it == indexSet.end()) continue;

                topNext = nums[*it];
                int sum = nums[top.second] + topNext;

                nums[top.second] = sum;

                pq.push({nums[*itFirst] + sum, *itFirst});
                auto itSecond = indexSet.upper_bound(*it);
                if(itSecond != indexSet.end()){
                    pq.push({sum + nums[*itSecond], top.second});
                }
                cout<<"index: "<<top.second<<endl;
                cout<<"lower: "<<*itFirst<<endl;
                cout<<"Upper: "<<*itSecond<<endl;
                
                indexSet.erase(*it);
                count++;
            }
        }

        return count;
    }
};
