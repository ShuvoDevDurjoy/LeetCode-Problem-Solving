#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &nums , int size,  int pivot){
    cout<<"Here pivot is : "<<pivot<<endl;
    if(pivot>=0)
    {
    int value = nums[size] ; 
    int i = 0 ; 
    for (i = size-2 ; i > 0 ; --i  ){
        if(nums[i]>value){
            nums[i+1] = nums[i] ; 
        }
        else 
        break ; 
    }
    if(i!=size-2)
   { nums[i+1] = nums[i] ; 
    nums[i] = value ; 
   }
    quickSort(nums,size , pivot-1) ; 
    }
}

void mergeSort(vector<int> &nums , int left , int right , int mid ){
    int l = mid - left + 1; 
    int r = right - mid ; 

    int arr1[mid-left+1] ; 
    for(int i = 0 ; i < mid-left+1 ; ++i){
        arr1[i] = nums[left+i] ; 
        cout<<"Here arr1 is : "<<arr1[i]<<endl;
    }
    cout<<endl;

    int arr2[right - mid] ; 
    for(int i = 0 ;i < right-mid ; ++i){
        arr2[i] = nums[mid+i+1] ; 
    }


    int leftIndex = 0 ; 
    int rightIndex = 0 ; 

    int index = left ; 
    while(leftIndex < l && rightIndex < r){
        if(arr1[leftIndex] < arr2[rightIndex])
        {
            nums[index++] = arr1[leftIndex++] ; 
        }
        else {
            nums[index++] = arr2[rightIndex++] ; 
        }
    }

    while(leftIndex<l){
        nums[index++] = arr1[leftIndex++] ; 
    }
    while(rightIndex< r){
        nums[index++] = arr2[rightIndex++] ; 
    }
}


void merge(vector<int> &nums ,int left , int right){
    if(left<right){
        int mid = (left+right)/2 ; 
        merge(nums,left,mid) ; 
        merge(nums,mid+1 , right) ; 
        mergeSort(nums , left , right , mid) ; 
    }

}

vector<vector<int>> finding(vector<int> &nums){
    vector<vector<int>> result ; 
    int iIndex = 0 ; 
    int jIndex = 0 ; 
    int kIndex = 0 ; 
    for(int i = 0 ; i < nums.size()-2 ; i++){
        if(nums[i]==nums[i+1])
        {
            iIndex = i ; 
            continue ; 
        }
        else{for(int j = iIndex+1 ; j < nums.size()-1 ; ++j){
            cout<<"Here i is  : "<<i << endl;
            if(nums[j] == nums[j+2])
            {
                jIndex = j ;
                continue ; 
            }
            for(int k = j ; k < nums.size() ; k++){
                if(nums[k] == nums[k+2])
                {
                    kIndex = k ;
                    continue ; 
                }
                else if(nums[i]+nums[j]+nums[k]==0 && iIndex!=jIndex && jIndex!=kIndex && iIndex!=kIndex)
                {
                    result.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
        }
        iIndex = i+1 ; 
    }
    return result ; 
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4} ; 
    merge(nums , 0 , nums.size()-1) ; 
    for(int i = 0 ; i < nums.size() ; ++ i){
        cout<<"Here is : "<<nums[i]<<endl;
    }


    vector<vector<int>> result = finding(nums) ; 
    for(int i = 0 ;i < result.size() ; i++){
        for(int j = 0 ; j < 3 ; ++j){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
