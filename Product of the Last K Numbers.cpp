class ProductOfNumbers {
public:
    vector<long long int> nums ; 
    int size = 0;
    int lastZeroIndex = -1;
    ProductOfNumbers() {
        nums.push_back(1l);
    }
    
    void add(int num) {
        if(num==0){
            nums.push_back(1l);
            lastZeroIndex = size;
            size++;
        }
        else{
            nums.push_back(nums[size]*num);
            size++;
        }
    }
    
    long long int getProduct(int k) {
        int index = size - k;
        if(index<=lastZeroIndex){
            return 0;
        }
        else{
            return nums[size]/nums[index];
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
