class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        sort(rs.begin(), rs.end());
        int index = 0;
        int count = 0;
        sort(rs.begin(), rs.end());
        int curr_index = rs[0][0];
        int num_unique = 0;
        int size = rs.size();

        while(index < size){
            int curr = rs[index][0];
            ++num_unique;
            int start = 2;
            // cout<<"For index: "<<curr<<endl;
            while(index < size && rs[index][0]==curr){
                int end = rs[index][1];
                count += abs(end - start) / 4;
                // cout<<"    adding count for range: ("<<start<<", "<<end<<") and count: "<<((end - start) / 4)<<endl;
                start = end + (end % 2 == 0 ? 2: 1);
                index++;
            }
            // cout<<"    adding count for range: ("<<start<<", "<<10<<") and count: "<<((10 - start) / 4)<<endl;
            count += abs(10 - start) / 4;
        }

        count += (n - num_unique) * 2;
        return count;
    }
};
