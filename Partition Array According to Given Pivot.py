class Solution(object):
    def pivotArray(self, nums, pivot):
        """
        :type nums: List[int]
        :type pivot: int
        :rtype: List[int]
        """
        size = len(nums)
        left_index = 0
        right_index = size-1
        result = list(range(0,size))
        for a in nums:
            if a < pivot:
                result[left_index] = a
                left_index += 1
            elif a > pivot:
                result[right_index] = a
                right_index -= 1
        
        while left_index <= right_index:
            result[left_index] = pivot
            left_index += 1

        left_index = right_index + 1
        right_index = size-1

        while left_index < right_index:
            result[left_index], result[right_index] = result[right_index], result[left_index]
            left_index += 1
            right_index -= 1
        
        return result

        
