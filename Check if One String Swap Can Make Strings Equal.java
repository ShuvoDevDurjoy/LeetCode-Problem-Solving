class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if(s1.equals(s2)) return true;
        int size1 = s1.length();
        int size2 = s2.length();
        if(size1!=size2){
            return false;
        }

        int first = -1 , second = -1;
        for(int i = 0 ; i < size1 ; ++i){
            if(s1.charAt(i)!=s2.charAt(i)){
                if(first==-1){
                    first = i;
                }
                else if(second == -1){
                    second = i;
                }
                else{
                    return false;
                }
            }
        }
        if(first==-1 || second==-1){
            return false;
        }
        return s1.charAt(first)==s2.charAt(second) && s1.charAt(second)==s2.charAt(first);
    }
}
