//This is a function that will check if a given sequence of parantheses are right or not
bool isValid(string s) {
  //this array will work as a stack and size of the stack is half of the given string . Because, if a given sequence of parantheses is valid 
//than it must have equal number of opening bracket and closing bracket 
    int length = s.length() / 2;
    char *arr ; 
    if(s.length()/2 == 0)
    //as there is possibility to get only one parantheses as well in which case the division give result 0 which is not defined for the stack 
    arr = new char[s.length()/2+1];
    else {
        arr = new char [s.length()/2];
    }
//this keeps track of the index
    int index = 0;
  //this loop checks one by one parantheses
    for (int i = 0; i < s.length(); i++) {
//if parantheses is opening then it is stored in the stack 
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            if (index == s.length()/2) {
                return false;
            }
            arr[index++] = s[i];
        }
// As program will come to the point if the bracket is not opening
//if the stack is empty then there is no opening bracket so if any closing bracket is found then this will be invalid .
        else if (index == 0) {
            return false;
        }
      else if (s[i] == ')' && arr[--index] != '(') {
            return false;
        } else if (s[i] == '}' && arr[--index] != '{') {
            return false;
        } else if (s[i] == ']' && arr[--index] != '[') {
            return false;
        }
    }
//after the loop if stack is empty then this will return true or false 
    if(index==0)
    return true;
    else 
    return false ;
}
