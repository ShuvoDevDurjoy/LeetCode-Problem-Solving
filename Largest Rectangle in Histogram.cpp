class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i < heights.size(); ++i){
            int index = i;
            while(!st.empty() && heights[st.top()] > heights[i]){
                int h = heights[st.top()];
                int w = i - st.top();
                index = min(index, st.top());
                st.pop();
                maxArea = max(maxArea, w * h);
            }
            heights[index] = heights[i];
            st.push(index);
        }

        while(!st.empty()){
            int h = heights[st.top()];
            int w = heights.size() - st.top();
            maxArea = max(maxArea, w * h);
            st.pop();
        }

        return maxArea;
    }
};
