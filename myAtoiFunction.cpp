//This function converts a string to a number will all the following conditions : 
/*Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.*/
    int myAtoi(string s) {
        int len = s.length();
    long num  = 0 ; 
    int sign = 0 ; 
    bool l = false ;
    bool c = false ;  
    if(s[0]=='0')
        l = true ; 
    for(int i = 0 ; i < len ; i++)
    {
        if(s[i]==' ')
        {
            if(c)
            {
                break ;
            }
            continue ;
        }
        else if(s[i]=='-')
        {
            if(l)
            {
                return 0 ; 
            }
           else if(!c&&sign==0)
            {
                sign = -1 ; 
                c=true ; 
            }
            else break ; 
        }
        else if(s[i]=='+')
        {
            cout<<"inside +"<<endl;
            if(l)
            {
                return 0 ; 
            }
           else if(!c&&sign==0)
            {sign = 1 ; 
            c=true ;
            }
            else break ; 
        }
        else if((s[i]>='0'&&s[i]<='9')&&(sign==-1)&&(num*10+(s[i]-'0'))>=2147483648)
        {
            return -2147483648;
        }
        else if((s[i]>='0'&&s[i]<='9')&&(sign==1||sign==0)&&(num*10+(s[i]-'0'))>=2147483647)
        {
            return 2147483647;
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            c = true ; 
            num = num*10 + (s[i]-'0') ;
            if(num>0)
            {
                l = false;
            }
        }
        else if(i>0&&(s[i-1]==' '))
        {
            break ; 
        }
        else if(s[i]=='.')
        {
            break;
        }
        else break ; 
    }
    return num*((sign==0)?1:sign) ;
    }
