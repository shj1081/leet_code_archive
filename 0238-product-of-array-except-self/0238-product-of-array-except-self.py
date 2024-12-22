class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        n = len(nums)
        result = [1] * n

        temp = 1
        zero_count = 0
        for i in range(n):
            if nums[i] == 0:
                zero_count += 1
                continue
            else:
                temp *= nums[i]

        if zero_count == 0:
            for i in range(n):
                result[i] = temp // nums[i]
        elif zero_count == 1:
            for i in range(n):
                if nums[i] == 0:
                    result[i] = temp
                else:
                    result[i] = 0
        else:
            result = [0] * n

        return result
