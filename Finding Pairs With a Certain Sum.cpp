class FindSumPairs {
private:
    vector<int> nums1; 
    vector<int> nums2;
    unordered_map<int,int> maps;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(auto e: nums2){
            maps[e]++;
        }
    }
    
    void add(int index, int val) {
        int value = nums2[index];
        maps[value]--;
        nums2[index] += val;
        maps[value + val]++;
    }
    
    int count(int tot) {
        int result = 0;
        for(int i = 0; i < nums1.size() && nums1[i] < tot; ++i){
            result += maps[tot - nums1[i]];
        }
        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
