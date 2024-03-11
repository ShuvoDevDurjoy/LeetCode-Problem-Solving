int check(char c){
    int value = 0 ; 
    switch(c){
                case 'I' : value = 1 ; 
                break ; 
                case 'V' : value = 5 ; 
                break; 
                case 'X' : value = 10 ; 
                break;
                case 'L' : value = 50 ;
                break;
                case 'C' : value = 100 ;
                break;
                case 'D' : value = 500 ;
                break;
                case 'M' : value = 1000 ;
            }
        return value ; 
}
    int romanToInt(string s) {
        int sum = 0 ; 
        if(s.length()==1){
            sum = check(s[0]);
        }
        else{ 
        for (int i = 0 ; i < s.length() ; ++i ){
            if(check(s[i])>=check(s[i+1])){
                sum += check(s[i]);
            }

            else {
                sum += (check(s[i+1])-check(s[i]));
                i++ ; 
            }
        }
        }
        return sum ; 
    }
