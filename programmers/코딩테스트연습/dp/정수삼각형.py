def solution(triangle):
    memory = [[0 for j in range(len(triangle[i]))] for i in range(len(triangle))]
    for i in range(len(triangle)):
        for j in range(len(triangle[i])):
            if i == 0 and j == 0:
                memory[i][j] = triangle[i][j]
            else:
                local_accum = []
                back_ind, forward_ind = j - 1, j
                if back_ind >= 0 and back_ind < len(triangle[i - 1]):
                    local_accum.append(memory[i - 1][back_ind])

                if forward_ind >= 0 and forward_ind < len(triangle[i - 1]):
                    local_accum.append(memory[i - 1][forward_ind])

                memory[i][j] = triangle[i][j] + max(local_accum)
    answer = max(memory[-1])
    return answer


if __name__ == "__main__":
    triangle = [[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]
    print(solution(triangle))