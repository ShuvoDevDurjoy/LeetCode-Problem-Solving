class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        //sort hbars and vbars for easier iteration
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int mhs = 0;
        int mvs = 0;
        int left = 0;
        for(int i = 1; i < hBars.size(); ++i){
            if(hBars[i] -1 != hBars[i-1]){
                left = i;
            }
            mhs = max(mhs, i - left);
        }

        left = 0;
        for(int i = 1; i < vBars.size(); ++i){
            if(vBars[i] - 1 != vBars[i-1]){
                left = i;
            }
            mvs = max(mvs, i - left);
        }

        int sideLength = min(mhs + 2, mvs + 2);
        return sideLength * sideLength;
    }
};
