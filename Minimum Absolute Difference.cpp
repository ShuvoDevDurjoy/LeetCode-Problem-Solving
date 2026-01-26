class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int minimumAbs = abs(arr[1] - arr[0]);
        for(int i = 1; i < arr.size(); ++i){
            minimumAbs = min(minimumAbs, abs(arr[i] - arr[i-1]));
        }

        vector<vector<int>> result;

        int left = 0, right = 1;
        while(right < arr.size()){

            while(left < right && abs(arr[right] - arr[left]) >= minimumAbs){
                if(abs(arr[right] - arr[left]) == minimumAbs){
                    result.push_back({arr[left], arr[right]});
                }

                left++;
            }

            right++;
        }

        return result;
    }
};
