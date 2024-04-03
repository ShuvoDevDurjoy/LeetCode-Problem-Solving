class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer; 
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        nums1.erase(unique(nums1.begin(),nums1.end()),nums1.end());
        nums2.erase(unique(nums2.begin(),nums2.end()),nums2.end());
        int size1 = nums1.size() ; 
        int size2 = nums2.size() ; 
        answer.push_back({}) ; 
        answer.push_back({}) ;
        for(int i =  0 ; i < size1 ; ++i){
            bool found = false ; 
            for(int j = 0 ; j < size2 ; ++j){
                if(nums1[i] == nums2[j])
                {
                    found = true ; 
                    break ; 
                }
            }
            if(!found){
                answer[0].push_back(nums1[i]) ; 
            }
        }

        for(int i =  0 ; i < size2 ; ++i){
            bool found = false ; 
            for(int j = 0 ; j < size1 ; ++j){
                if(nums2[i] == nums1[j])
                {
                    found = true ; 
                    break ; 
                }
            }
            if(!found){
                answer[1].push_back(nums2[i]) ; 
            }
        }

        return answer ; 
    }
};
