class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        num = abs(x)
        mul = 10
        res = 0
        while (num):
            res *= 10
            res += num % mul
            num = num // 10
        if x > 0 and res < 2 ** 31: 
            return res
        elif x < 0 and res <= 2 ** 31:
            return -res
        else:
            return 0
