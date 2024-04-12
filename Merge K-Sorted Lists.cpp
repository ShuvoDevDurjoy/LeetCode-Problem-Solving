class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxleft(height.size(),0) ; 
        vector<int> maxright(height.size(),0);
        int maximum = height[0] ; 
        for(int i = 0 ; i < height.size() ; ++i){
            maxleft[i] = max(maximum,height[i]) ; 
            maximum = max(maximum,height[i]) ; 
        }
        maximum = height[height.size()-1] ; 
        for(int i = height.size()-1 ; i>=0 ; --i){
            maxright[i] = max(maximum ,height[i] );
            maximum = max(maximum,height[i]) ; 
        }
        int sum = 0 ; 
        for(int i = 0 ;i < height.size() ; ++i){
            sum+=min(maxleft[i],maxright[i])-height[i] ; 
        }
        return sum ; 
    }
};
