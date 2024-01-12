def checkBomb(i, j, board, cnt, visited):
    for di in [-1, 0, 1]:
        for dj in [-1, 0, 1]:
            if 0 <= i+di < len(board) and 0 <= j+dj < len(board) and [i+di, j+dj] not in visited:
                cnt += 1
                visited.append([i+di, j+dj])
    return cnt, visited
def solution(board):
    cnt = 0
    visited = []
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 1 not in visited:
                cnt, visited = checkBomb(i, j, board, cnt, visited)
            else:
                continue
    return len(board) * len(board) - cnt


if __name__ == "__main__":
    # print(solution([[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [ 0, 0, 0, 0, 0], [0, 0, 1, 0, 0], [0, 0, 0, 0, 0]]))
    # print(solution([[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 1, 1, 0], [0, 0, 0, 0, 0]]))
    print(solution([[0, 1, 0], [0, 0, 0], [0, 0, 1]]))
