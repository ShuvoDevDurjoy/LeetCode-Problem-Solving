class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i = 0 ; i < arr.size() ; ++i)
        {
            cout<<arr[i]<<" " ; 
            if(i%15==0) cout<<endl;
        }
        cout<<endl;
        for(int i = 0 ; i < arr.size() ; ++i){
            for(int j = i+1 ; j < arr.size(); ++j){
                if(arr[i]>=0 && arr[j]==arr[i]*2) return true ; 
                if(arr[i]<0 && arr[j]*2==arr[i]) return true ; 
            }
        }
        return false ; 
    }
};
