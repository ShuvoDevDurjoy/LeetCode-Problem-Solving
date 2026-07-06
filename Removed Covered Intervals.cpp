class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] < b[0]) return true;
            return a[0]==b[0] && a[1] > b[1];
        });


        int size = intervals.size();

        int removed = 0;

        int prev = 0;

        for(int i = 1; i < size; ++i){

            int a = intervals[prev][0];
            int b = intervals[prev][1];
            int c = intervals[i][0];
            int d = intervals[i][1];


            if(a <= c && b >= d){
                removed++;
            }
            else{
                prev = i;
            }
        }

        return size - removed;
    }
};
