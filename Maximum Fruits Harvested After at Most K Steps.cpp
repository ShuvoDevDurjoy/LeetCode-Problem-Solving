class Solution {
public:
    int binarySearch(vector<vector<int>> &f, int index){
        int left = 0;
        int right = f.size()-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(f[mid][0]==index){
                return f[mid][1];
            }
            else if(f[mid][0] > index){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return 0;
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int size = fruits.size();
        vector<int> prefixSums(max(startPos+1, fruits[size-1][0]+1), 0);
        int i = startPos-1, j = startPos+1;
        prefixSums[startPos] = binarySearch(fruits, startPos);
        while(i >= 0 && j <= fruits[size-1][0]){
            prefixSums[i] += binarySearch(fruits, i) + prefixSums[i+1];
            prefixSums[j] += binarySearch(fruits, j) + prefixSums[j-1];
            i--;
            j++;
        }

        while( i>=0){
            prefixSums[i] += binarySearch(fruits, i) + prefixSums[i+1];
            i--;
        }

        while(j <= fruits[size-1][0]){
           prefixSums[j] += binarySearch(fruits, j) + prefixSums[j-1];
           j++; 
        }
        int maximum = prefixSums[startPos];
        // for(auto &x: prefixSums){
        //     cout<<x<<", ";
        // }
        // cout<<endl;
        // go left and also check for turn right
        for(int x = startPos ; x >= max(startPos - k, 0); x--){
            int distance = min(startPos + k - 2 * (startPos - x), fruits[size-1][0]);
            // cout<<"Distance is : "<<distance<<endl;
            int value = 0;
            if(distance > startPos)
            {
                value = prefixSums[distance];
            }
            // cout<<"x: "<<x<<" sum : "<<prefixSums[x]+value-prefixSums[startPos]<<endl;

            maximum = max(prefixSums[x]+value-prefixSums[startPos], maximum);
        }

        for(int x = startPos; x <= min(startPos + k, fruits[size-1][0]); ++x){
            int distance = max(startPos - (k - 2 * (x - startPos)), 0);
            // cout<<"distance is : "<<distance<<endl;
            int value = 0;
            if(distance < startPos){
                value = prefixSums[distance];
            }
            // cout<<"x: "<<x<<" sum : "<<prefixSums[x]+value-prefixSums[startPos]<<endl;
            maximum = max(prefixSums[x]+value-prefixSums[startPos], maximum);
        }

        return maximum;
    }
};
