class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        res = digits
        i = len(res) - 1
        for i in range(len(res) - 1, -1, -1):
            if res[i] != 9:
                res[i] += 1
                break 
            else:
                res[i] = 0
        if (i == 0 and res[i] == 0):
            res[i] = 1
            res.append(0)
        return res