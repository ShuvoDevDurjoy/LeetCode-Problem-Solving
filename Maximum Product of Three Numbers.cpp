class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while(n){
            arr.push_back(n % 10);
            n = n / 10;
        }

        int max_product = 0;
        for(int i = 0; i < arr.size(); ++i){
            for(int j = i + 1; j < arr.size(); ++j){
                max_product = max(max_product, arr[i] * arr[j]);
            }
        }

        return max_product;
    }
};
