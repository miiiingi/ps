from collections import deque


def move(y0, x0, y1, x1):
    answer = []
    y0, x0, y1, x1 = y0 - 1, x0 - 1, y1 - 1, x1 - 1
    for t_x in range(x0, x1):
        answer.append([y0, t_x])
    for r_y in range(y0, y1):
        answer.append([r_y, x1])
    for b_x in range(x1, x0, -1):
        answer.append([y1, b_x])
    for l_y in range(y1, y0, -1):
        answer.append([l_y, x0])
    return answer


def solution(rows, columns, queries):
    matrix = [[0 for _ in range(columns)] for _ in range(rows)]
    num = 1
    result = []
    for i in range(rows):
        for j in range(columns):
            matrix[i][j] = num
            num += 1
    elem_list = deque()
    for query in queries:
        start_y, start_x, end_y, end_x = query
        move_list = move(start_y, start_x, end_y, end_x)
        move_list = deque(move_list)
        for m in move_list:
            my, mx = m
            elem_list.append(matrix[my][mx])
        result.append(min(elem_list))
        move_list.rotate(-1)
        for m in move_list:
            my, mx = m
            matrix[my][mx] = elem_list.popleft()
    return result
