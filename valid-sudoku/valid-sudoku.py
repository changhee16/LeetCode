class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        new_board = list(zip(*board))
        new_board_2 = []

        for i in range(0, 9, 3): # 3* 3 indexing
            for j in range(0, 9, 3):
                block = []
                for row in board[i:i+3]:
                    block.append(row[j:j + 3])
                new_board_2.append(list(chain(*block)))
        print(new_board_2)     
        
        
        for i in range(0, 9): #중복 확인 
            dict = {}
            for j in range(0, 9):
                if board[i][j] not in dict and board[i][j] != '.':
                    dict[board[i][j]] = 1
                elif board[i][j] in dict:
                    return False
        for i in range(0, 9): #중복 확인 
            dict = {}
            for j in range(0, 9):
                if new_board[i][j] not in dict and new_board[i][j] != '.':
                    dict[new_board[i][j]] = 1
                elif new_board[i][j] in dict:
                    return False
        for i in range(0, 9): #중복 확인 
            dict = {}
            for j in range(0, 9):
                if new_board_2[i][j] not in dict and new_board_2[i][j] != '.':
                    dict[new_board_2[i][j]] = 1
                elif new_board_2[i][j] in dict:
                    return False
        return True