class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        orj = copy.deepcopy(matrix)
        end = len(matrix)
        for i in range(0, end):
            for j in range(0, end):
                matrix[j][end - 1 - i] = orj[i][j]