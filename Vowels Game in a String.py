class Solution(object):
    def doesAliceWin(self, s):
        """
        :type s: str
        :rtype: bool
        """
        count = 0 
        for i in s:
            if(i=='a' or i == 'e' or i=='i' or i=='o' or i=='u'):
                count = count+1
        if(count==0):
            return False
        return True
