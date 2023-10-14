class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        new_nums = set(nums)
        if (len(new_nums) != len(nums)):
            return True
        else:
            False