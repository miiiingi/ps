def solution(n, computers):
    visited = [False for _ in range(n)]
    cnt = 0

    def dfs(i):
        visited[i] = True
        for j in range(n):
            if i == j:
                continue
            print(f"i: {i}, j: {j}")
            if computers[i][j] == 1 and not visited[j]:
                dfs(j)

    for i in range(n):
        if not visited[i]:
            dfs(i)
            cnt += 1
    return cnt


if __name__ == "__main__":
    print(solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]))
