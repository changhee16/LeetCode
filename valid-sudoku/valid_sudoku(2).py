class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """

        rows = [list() for _ in range(9)]
        cols = [list() for _ in range(9)]
        boxes = [list() for _ in range(9)]

        for r in range(9):
            for j in range(9):
                chk = board[r][j]

                if chk == '.':
                    continue
                if chk in rows[r]:
                    return False
                rows[r].append(chk)
                if chk in cols[j]:
                    return False
                cols[j].append(chk)
                if chk in boxes[(r // 3) * 3 + j // 3]:
                    return False
                boxes[(r // 3) * 3 + j // 3].append(chk)
        return True