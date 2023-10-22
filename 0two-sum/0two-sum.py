class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        map = {}
        for i in range(0, len(nums)):
            other = target - nums[i]
            if other in map:
                return [i, map[other]]
            map[nums[i]] = i