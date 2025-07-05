class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> maps;
        int largest = -1;
        for (const int& a : arr) {
            maps[a]++;
        }

        for (auto& value : maps) {
            if (value.first == value.second) {
                largest = max(largest, value.first);
            }
        }

        return largest;
    }
};
