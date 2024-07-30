def dfs(grid, i, j) : 
    # dfs에서는 어떤 경우에 카운트 하지 않을 것인지를 생각해주는 것이 중요!!
    if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] != '1' :  
        return
    # 만약 0으로 바꿔주지 않으면, 탐색 했던 곳을 또 탐색 할 것 이므로, 탐색 했으면 0으로 바꿔주는 과정이 필요
    grid[i][j] = '0'
    dfs(grid, i-1, j) #
    dfs(grid, i+1, j)
    dfs(grid, i, j-1) #
    dfs(grid, i, j+1)

def islands(grid) : 
    count = 0 
    for i in range(len(grid)) : 
        for j in range(len(grid[0])) : 
            if grid[i][j] == '1' : 
               dfs(grid, i, j) 
               count += 1
    return count