class Solution {
public:

    string gcdOfStrings(string str1, string str2) {
    if(str1 + str2 != str2+str1){
            return "";
        }
        int gcdLength = 0;
        int a = str1.size();
        int b = str2.size();
        int remainder = 0;
        while(b != 0){
            gcdLength = b;
            remainder = a % b;
            a = b;
            b = remainder;
        }
        return str1.substr(0, gcdLength);
    }
};
