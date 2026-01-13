class Solution {
public:
    double FindAreaBelow(vector<vector<int>> &s, double y){
        double area_under = 0.0;
        int size = s.size();
        for(int i = 0; i < size && ((s[i][1] * 1.0) <= y); ++i){
            if((s[i][1] * 1.0) <= y && y <= ((s[i][1] + s[i][2]) * 1.0)){
                area_under += (y - s[i][1] * 1.0) * s[i][2];
            }
            else{
                area_under += s[i][2] * 1.0 * s[i][2];
            }
        }

        return area_under;
        
    }
    double separateSquares(vector<vector<int>>& squares) {
        sort(squares.begin(), squares.end(), [](vector<int> &a, vector<int> &b){return a[1] < b[1];});
        double total_area = 0;
        int size = squares.size();
        double left; 
        double right;
        for(int i = 0; i < size; ++i){
            total_area += squares[i][2] * 1.0 * squares[i][2] * 1.0;
            left = min(left, squares[i][1] * 1.0);
            right = max(right, squares[i][1] * 1.0 + squares[i][2]);
        }
        double half_area = total_area / 2.0;
        // start the binary search
        double y = 0.0;
        while((right - left) > 0.00001){
            double mid = left + (right - left) / 2.0;
            double AreaUnderMid = FindAreaBelow(squares, mid);
            if(AreaUnderMid >= half_area){
                right = mid;
                y = mid;
            }
            else{
                left = mid;
            }
        }
        return y;
    }
};
