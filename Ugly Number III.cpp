class Solution {
public:
    long lcm(long a, long b){
        return (a * b) / gcd(a, b);
    }
    long lcm3(long a, long b, long c){
        return lcm(lcm(a, b), c);
    }
    long find(long a, long b, long c, long k){
        long result = ((k / a) + (k / b) + (k / c)) - (k / lcm(a, b)) - (k / lcm(a, c)) - (k / lcm(b, c)) + (k / lcm3(a, b, c));
        return result;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
       long long lcm_of_3_numbers = lcm3(a, b, c);
       long counts = n / find(a, b, c, lcm_of_3_numbers);
       long left = lcm_of_3_numbers * counts;
       if(left == 0) left = 1;
       long right =  lcm_of_3_numbers * (counts + 1);
    //    cout<<"left is : "<<left<<" and right is : "<<right<<endl;
       while(left <= right){
        long long mid = left + (right - left ) / 2;
        // cout<<"mid is : "<<mid<<endl;
        long count = find(a, b, c, mid);
        // cout<<"count is : "<<count<<endl;
        if(count == n && (n/a==0 || n/b==0 || n/c==0)){
            return mid;
        } 
        else if(count == n && !(n/a==0 || n/b==0 || n/c==0)){
            right = mid - 1; 
        }
        else if( count < n ){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
       }
       return left;
    }
};
