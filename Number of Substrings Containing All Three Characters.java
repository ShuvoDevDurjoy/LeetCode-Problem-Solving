class Solution {
    public int numberOfSubstrings(String s) {
        int size = s.length();
        int a_pos = -1, b_pos = -1, c_pos = -1;
        int minimum_index = -1;
        int count = 0;
        int i = 0;
        for(char x : s.toCharArray()){
            if(x=='a') a_pos = i++;
            else if(x=='b') b_pos = i++;
            else if(x=='c') c_pos = i++;
            minimum_index = Math.min(Math.min(a_pos, b_pos), c_pos);
            if(minimum_index >= 0){
                count += minimum_index + 1;
            }
        }

        return count;
    }
}
