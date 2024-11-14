class Solution(object):
    def getLastMoment(self, n, left, right):
        """
        :type n: int
        :type left: List[int]
        :type right: List[int]
        :rtype: int
        """
        left = sorted(left)
        right = sorted(right)
        size = len(right)
        if(len(left)==0):
            return n-right[0]
        elif(len(right)==0):
            return left[-1]
        return left[-1] if (left[-1]>(n-right[0])) else n-right[0]
        
