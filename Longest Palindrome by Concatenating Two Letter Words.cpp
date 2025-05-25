class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> maps;
        for(string& word: words){
            maps[word]++;
        }
        cout<<endl;

        bool foundDuplicate = false;
        int count = 0;

        for(int i = 0; i < words.size(); ++i){
            string original = words[i];
            string word = original;
            reverse(word.begin(), word.end());
            if(min(maps[original], maps[word])){
                if(original[0]!=original[1]){
                    count += min(maps[original], maps[word]);
                }
                else{
                    count += maps[original] / 2;
                    if(maps[original]%2){
                        foundDuplicate = true;
                    }
                }

                maps[word] = 0;
                maps[original] = 0;
            }
        }
        int result = count * 4;
        if(foundDuplicate){
            result += 2;
        }


        return result;
    }
};
