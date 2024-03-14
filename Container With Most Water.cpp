int maxArea(vector<int>& height) {
        int max = 0 ; 
    vector<int>::iterator left = height.begin();
    vector<int>::iterator right = height.end()-1; 
    while(left!=right){
        int area = min(*left,*right) * (right-left) ; 
        max = max > area? max : area ; 
        if(*left < *right)
        {
            ++left ; 
        }
        else
        {
            --right ; 
        }
    }
    return max ; 
    }
