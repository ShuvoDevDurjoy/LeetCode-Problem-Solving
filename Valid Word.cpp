class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    bool isValid(string word) {
        int size = word.size();
        bool foundVowel = false, foundConsonent = false;
        for(int i = 0; i < size; ++i){
            if(! isalnum(word[i])){
                return false;
            }
            if(! foundVowel && isVowel(word[i])){
                foundVowel = true;
            }
            if(! foundConsonent && !isVowel(word[i]) && !isdigit(word[i])){
                foundConsonent = true;
            }
        }

        if(word.size() >= 3 && foundVowel && foundConsonent) return true;
        return false;
    }
};
