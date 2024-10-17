class Solution {
public:
    int maximumSwap(int num) {
        int sampleNum = num;
    int size = 0;
    while (sampleNum)
    {
        sampleNum /= 10;
        ++size;
    }
    sampleNum = num;
    int arr1[size];
    int index = size - 1;
    while (sampleNum)
    {
        arr1[index--] = sampleNum % 10;
        sampleNum /= 10;
    }
    int max_index;
    for (int i = 0; i < size; ++i)
    {
        max_index = i;
        for (int j = i; j < size; ++j)
        {
            if (arr1[j] == -1)
                continue;
            if (arr1[j] >= arr1[max_index])
            {
                max_index = j;
            }
        }
        if (arr1[max_index] != arr1[i])
        {
            int m = arr1[max_index];
            arr1[max_index] = arr1[i];
            arr1[i] = m;
            break;
        }
    }
    num = 0 ; 
    for(int i = 0 ; i < size ; ++i){
        num = num * 10 + arr1[i];
    }
    return num; 
    }
};
