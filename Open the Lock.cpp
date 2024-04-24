class Solution {
public:
    string findingNextCombination(string s , int index)
{
   if(s[index]=='9')
   {
      s[index] = '0' ; 
      return s ; 
   }
   else {
      s[index] = s[index]+1; 
      return s; 
   }
}

string findingPreviousCombination(string s,int index)
{
   if(s[index]=='0')
   {
      s[index] = '9' ; 
      return s ; 
   }
   else {
      s[index] = s[index]-1 ; 
      return s ; 
   }
}

bool findingInDeadLock(vector<string> &dead , string target)
{
   for(int i = 0 ; i < dead.size() ; ++i)
   {
      if(dead[i]==target)
      return true ; 
   }
   return false ; 
}

bool findingInVisited(vector<string> &visited , string target)
{
   for(int i = 0 ;i < visited.size() ; ++i)
   {
      if(visited[i]==target)
      return true ; 
   }
   return false ; 
}

int openLock(vector<string> &deadlock , string target)
{
   queue<string> combinations ;
   unordered_set<string> visited ; 
   for(int i = 0 ; i < deadlock.size() ; ++i)
   {
      visited.insert(deadlock[i]) ; 
   }
   int count = 0 ; 
   if(visited.find("0000")!=visited.end())
   {
      return -1 ; 
   } 
   combinations.push("0000") ; 
   visited.insert("0000") ; 


   while(!combinations.empty())
   {
      for(int i = combinations.size() ; i>0 ; --i)
      {
         string front = combinations.front() ; 
         if(front==target)
         {
            return count ; 
         }
         combinations.pop() ; 
         for(int i = 0 ; i < 4 ; ++i)
         {
            string current = findingNextCombination(front,i) ; 
            if(visited.find(current)==visited.end()){
                  combinations.push(current) ; 
                  visited.insert(current) ; 
            }
            current = findingPreviousCombination(front,i) ; 
            if(visited.find(current)==visited.end()){
                  combinations.push(current) ; 
                  visited.insert(current) ; 
            }
         }
      }
      ++count ; 
   }
   return -1 ; 

}
};
