class Solution {
public:
    int smallestNumber(int n, int t) {
        bool found = false;
        while(found == false){
            int x = n;
            int p = 1;
            while(x && p){
                p *= (x % 10);
                x /= 10;
            }

            if(p % t == 0){
                found = true;
                continue;
            }
            n++;
        }

        return n;
    }
};
