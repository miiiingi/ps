def search(i, j, maps, visited):
    if i < 0 or i >= len(maps) or j < 0 or j >= len(maps[0]) or maps[i][j] == 'X':
        return visited
    visited.append(int(maps[i][j]))
    maps[i] = maps[i][:j] + 'X' + maps[i][j+1:]
    visited = search(i-1, j, maps, visited)
    visited = search(i+1, j, maps, visited)
    visited = search(i, j-1, maps, visited)
    visited = search(i, j+1, maps, visited)
    return visited


def solution(maps):
    answer = []
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if maps[i][j] != 'X':
                visited = search(i, j, maps, visited=[])
                answer.append(sum(visited))
    if len(answer) == 0:
        return [-1]
    return answer.sort()


if __name__ == "__main__":
    print(solution(["X591X", "X1X5X", "X231X", "1XXX1"]))
