class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        new_nums = nums
        new_nums.sort()
        for i in range(0, len(new_nums), 2):
            if i == len(new_nums) - 1:
                return new_nums[i]
            elif (new_nums[i] != new_nums[i + 1]):
                return new_nums[i]