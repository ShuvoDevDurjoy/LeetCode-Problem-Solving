class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<vector<int>> result;
        int i = 0 , j = 0 ;
        while(i<size1 && j<size2){
            if(nums1[i][0]>nums2[j][0]){
                result.push_back({nums2[j][0],nums2[j][1]});
                j++;
            }
            else if(nums1[i][0]<nums2[j][0]){
                result.push_back({nums1[i][0],nums1[i][1]});
                i++;
            }
            else{
                result.push_back({nums1[i][0],nums1[i][1]+nums2[j][1]});
                i++;
                j++;
            }
        }

        while(i<size1){
            result.push_back({nums1[i][0],nums1[i][1]});
            i++;
        }

        while(j<size2){
            result.push_back({nums2[j][0],nums2[j][1]});
            j++;
        }

        return result;
    }
};
