class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1) return 1 ; 
    else if(nums.size()==2) return nums[0]<nums[1]? 2 : 1 ;
    vector<int> dynamic(nums.size(),1) ; 
    int size = nums.size() - 1; 
    int index = size - 1; 
    while(index>=0){
        int i = index+1 ; 
        int maximum = 0 ; 
        while(i<=size)
        {
            if(nums[index]<nums[i])
            {
                maximum = (maximum<dynamic[i])?dynamic[i]:maximum ; 
            }
            // cout<<"maximum : "<<maximum<<endl;
            i++ ; 
        }
            dynamic[index] = dynamic[index]+maximum ; 
        // cout<<endl;
        index-- ; 
    }
    int max = 0 ; 
    // for(int i = 0 ; i <= size ; ++i){
    //     cout<<dynamic[i]<<endl;
    // }
    for(int i = 0 ; i <=size ; ++i){
        if(dynamic[i]>max){
            max = dynamic[i] ; 
        }
    }
    return max ; 
    }
};
