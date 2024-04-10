class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end()) ; 
    vector<int>result(deck.size(),0) ; 
    queue<int> indexes ; 
    for(int i = 1 ; i < deck.size() ; ++i)
    {
        indexes.push(i) ; 
    }
    result[0] = deck[0] ; 
    int index = 1 ; 
    while(!indexes.empty())
    {
        if(indexes.size()==1)
        {
            result[indexes.front()] = deck[index++] ; 
            indexes.pop() ; 
        }
        else {
            int x = indexes.front() ; 
            indexes.push(x) ; 
            indexes.pop() ; 
            result[indexes.front()] = deck[index++] ; 
            indexes.pop() ; 
        }
    }
    return result ;
    }
};
