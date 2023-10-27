class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        s = str(x)
        if s[0] == '-':
            s = '-' + s[:0:-1]
        else:
            s = s[::-1]
        res = int(s)
        if res > (2 ** 31 - 1) or res < (-2 ** 31) :
            return 0        
        return int(s)