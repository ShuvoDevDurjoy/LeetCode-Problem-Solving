class Solution(object):
    def makeFancyString(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        prev = s[0]
        s = list(s)
        mark = 1 
        for i in range(1,length):
            if s[i] == prev and mark >=2:
                prev = s[i]
                s[i]='.'
                mark = mark+1
            elif s[i] == prev and mark == 1:
                mark = mark+1
                prev = s[i]
            else : 
                mark = 1
                prev = s[i]
        result = []
        for i in range(0,length):
            if s[i] != '.':
                result.append(s[i])
        return ''.join(result)
        
