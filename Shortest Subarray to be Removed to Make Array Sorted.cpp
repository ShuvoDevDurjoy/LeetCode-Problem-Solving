class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int size = arr.size();
        // cout<<"size of the arr is : "<<size<<endl;
        int b = 1;
        int c = size - 2;
        while (b < size && arr[b] >= arr[b - 1]) {
            b++;
        }
        if (b == size) {
            return 0;
        }
        b--;
        while (c >= 0 && arr[c] <= arr[c + 1]) {
            c--;
        }
        c++;
        // cout<<"b is : "<<b<<" and c is : "<<c<<endl;
        // cout<<endl;
        int p = c;
        int mincount = size;
        for (int i = 0; i <= b; ++i) {
            while (p < size && arr[p] < arr[i]) {
                ++p;
            }
            if (mincount > (b - i + p - c)) {
                mincount = p - c + b - i;
            }
            // cout<<i<<" and "<<p<<endl;
        }
        // cout<<endl;
        // cout<<mincount<<endl;
        // cout<<endl;
        p = b;
        for (int i = size - 1; i >= c; --i) {
            while (p >= 0 && arr[p] > arr[i]) {
                p--;
            }
            if (mincount > (b - p + i - c)) {
                mincount = b - p + i - c;
            }
            // cout<<i<<" and "<<p<<endl;
        }
        // cout<<endl;
        // cout<<mincount<<endl;
        // cout<<endl;
        return size - (b + 1 + size - c) + mincount;
    }
};
