class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> maps;

        int size = digits.size();

        for(int i = 0 ; i < size; ++i){
            maps[digits[i]]++;
        }

        vector<int> result;

        for(int i = 100; i <= 999; ++i){
            int num1, num2, num3;
            num1 = i/100;
            num2 = (i%100)/10;
            num3 = i%10;
            if(num3%2) continue;

            if(!maps[num1]){
                i = num1 * 100 + 99;
                continue;
            }

            maps[num1]--;
            if(!maps[num2]){
                maps[num1]++;
                i = num1*100 + num2*10 + 9;
                continue;
            }
            maps[num2]--;
            if(!maps[num3]){
                maps[num1]++;
                maps[num2]++;
                continue;
            }
            maps[num1]++;
            maps[num2]++;
            result.push_back(i);

        }

        return result;
    }
};
