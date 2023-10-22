class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        res = []
        save = 0
        nums1.sort()
        nums2.sort()
        if (len(nums1) < len(nums2)):
            base = nums1
            compare = nums2
        else:
            base = nums2
            compare = nums1
        for i in range(0, len(base)):
            for j in range(save, len(compare)):
                if (base[i] < compare[j]):
                    break 
                elif (base[i] == compare[j]):
                    res.append(base[i])
                    save = j + 1
                    break 
        return res