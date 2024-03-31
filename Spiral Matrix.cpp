#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralOrder(int n ) {
    int downToUp = 1 ; 
    int upToDown = n-1 ; 
    int leftToRight = n-1 ; 
    int rightToLeft = 0 ;
    int size = n*n ; 
    bool l = true , r = false , b = false , u = false ;
    int row = 0 ; 
    int column = 0 ; 
    int value = 1 ; 
    vector<vector<int>> ans(n,vector<int>(n,0));

    for(int i = 0 ; i < size ; ++i)
    {
        if(l){
            if(column == leftToRight){
                ans[row][column] = value++ ;   
                leftToRight-- ; 
                row++ ; 
                l = false ; 
                b = true ; 
            }
            else{
                ans[row][column++] = value++ ; 
            }
        }
        else if(r){
            if(column == rightToLeft){
                ans[row][column] = value++ ;
                rightToLeft++ ; 
                row-- ; 
                r = false ; 
                u = true ;
            }
            else{
                ans[row][column--] = value++ ; 
            }

        }
        else if(b){
            if(row == upToDown){
                ans[row][column] = value++ ; 
                column-- ; 
                upToDown-- ; 
                b = false ; 
                r = true ;
            }
            else {
                ans[row++][column] = value++;
            }
        }
        else if(u){
            if(row == downToUp){
                ans[row][column] = value++ ;
                column++ ; 
                downToUp++ ;
                u = false ; 
                l = true ;
            }
            else {
                ans[row--][column] = value++ ;
            }

        }
    } 
    return ans ; 
    }
};
int main(){
    vector<vector<int>> matrix = {{1,2,3,4,5},
                                 {6,7,8,9,10},
                                 {11,12,13,14,15},
                                 {16,17,18,19,20},
                                 {21,22,23,24,25}};
    Solution s ; 
    vector<vector<int>> result = s.spiralOrder(4) ; 
    for(vector<int> i : result){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
}
