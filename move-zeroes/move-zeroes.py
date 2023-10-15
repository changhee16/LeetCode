class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        for i in range(0, len(nums)):
            if nums[i] == 0:
                k = i
                while k < len(nums) and nums[k] == 0:
                    k += 1
                if k == len(nums):
                    break 
                tmp = nums[i]
                nums[i] = nums[k]
                nums[k] = tmp
            