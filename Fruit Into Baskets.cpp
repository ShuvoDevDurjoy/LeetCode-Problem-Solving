class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> maps;
        int count = 0;
        int left = 0;
        int right = 0;
        int first = -1, second = -1;
        int subLeft = 1;
        int maximum = 0;
        for (int i = 0; i < fruits.size(); ++i) {
            if (first == -1) {
                first = fruits[i];
            } else if (second == -1 && fruits[i] !=first) {
                second = fruits[i];
                subLeft = i;
            }

            if (fruits[i] == first) {
                maps[first]++;
                maximum =
                    max(maximum, maps[first] + (second != -1 ? maps[second] : 0));
                    // cout<<"index is : "<<i<<" first is: "<<first<<" and second is : "<<second<<" and maximum is: "<<(maps[first]+(second!=-1?maps[second]:0))<<endl;
            } else if (fruits[i] == second) {
                maps[second]++;
                maximum = max(maximum, maps[first] + maps[second]);
                // cout<<"index is : "<<i<<" first is: "<<first<<" and second is : "<<second<<" and maximum is: "<<(maps[first]+maps[second])<<endl;
            } else {
                maximum = max(maximum, maps[first] + maps[second]);
                // cout<<"index is : "<<i<<" first is: "<<first<<" and second is : "<<second<<" and maximum is: "<<(maps[first]+maps[second])<<endl;
                i = subLeft - 1;
                maps[first] = 0;
                maps[second] = 0;
                first = -1;
                second = -1;
                subLeft++;
            }
        }
        return maximum;
    }
};
