class Solution(object):
    def titleToNumber(self, title):
        """
        :type columnTitle: str
        :rtype: int
        """
        x = 0 
        for i in range (len(title)-1, -1, -1):
            x = (ord(title[i])-64)*pow(26,len(title)-1-i) + x
        return x 
        
