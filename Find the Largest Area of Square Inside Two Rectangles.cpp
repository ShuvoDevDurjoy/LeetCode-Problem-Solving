class Solution {
public:
    int checkIntersect(int x1, int y1, int x2, int y2, int a1, int b1, int a2, int b2){
        bool doesIntersect = !(a2 < x1 || a1 > x2 || b2 < y1 || b1 > y2);
        if(doesIntersect){
            int inter_x = min(x2, a2) - max(x1, a1);
            int inter_y = min(y2, b2) - max(y1, b1);
            return min(inter_x, inter_y);
        }
        return 0;
    }
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
       int size = bottomLeft.size();
       long long maxSideLength = 0;
       for(int i = 0; i < size; ++i){
        for(int j = i + 1; j < size; ++j){
            long long sideLength = checkIntersect(bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1], bottomLeft[j][0], bottomLeft[j][1], topRight[j][0], topRight[j][1]);
            maxSideLength = max(maxSideLength, sideLength);
        }
       } 

       return maxSideLength * maxSideLength;
    }
};
