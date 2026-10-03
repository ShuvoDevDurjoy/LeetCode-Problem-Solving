class Solution {
public:
    int longestValidParentheses(string s) {
    int size = s.length() ; 
    if(size==0)return 0 ; 
    vector<int> arr(size, 0);
    stack<int> st ; 
    for(int i = 0 ; i < size ; ++i){
        if(s[i]=='('){
            st.push(i) ; 
        }
        else if(!st.empty() && s[i]==')')
        {
            int x= st.top() ;
            st.pop() ;
            for( ; x <= i && arr[x] == 0 ; ++x){
                arr[x]=1 ; 
            }
            int left = x;
            int right = i;
            while(left < right && (arr[left]==0 && arr[right]==0)){
                arr[left] = 1;
                arr[right] = 1;
                left++;
                right--;
            }
            while(left<right && arr[left]==0){
                arr[left] = 1;
                left++;
            }
            while(left<right && arr[right]==0){
                arr[right] = 1;
                right--;
            } 
        }
    } 
    int sum = 0; 
    int max = 0 ; 
    for(int i = 0 ; i < size ; ++i){
        if(arr[i]==1){
            sum+=arr[i] ; 
            if(sum>max){
            max = sum ; 
        }
        }
        else{
            sum = 0 ; 
        }
        
    }
    return max ; 
}

};
