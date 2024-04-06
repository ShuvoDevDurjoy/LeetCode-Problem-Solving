/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long int left = 1 ; 
        long int right = n ; 
        long int result = -1 ; 
        while(result!=0)
        result= guess((left+right)/2) ;
        if(result==-1) 
        {
            right = left-right ; 
        }
        else if(result==1)
        {
            left = left+right ; ;
        }
        
    return (left+right)/2 ; 
    }
};
