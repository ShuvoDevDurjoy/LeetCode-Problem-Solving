class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        size = len(blocks)
        whiteCount = 0
        for a in blocks[:k]:
            if a is 'W':
                whiteCount += 1
        if whiteCount is 0:
            return 0
        minimum = whiteCount
        for i in range(k,size):
            if blocks[i] is 'W':
                whiteCount += 1
            if blocks[i-k] is 'W':
                whiteCount -= 1
            
            minimum = min(minimum, whiteCount)
            if minimum is 0:
                return 0
        
        return minimum
