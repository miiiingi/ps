#include <iostream>
#include <vector>

using namespace std;

int m, n, pictureSize = 0;
vector<vector<int>> matrix;

void dfs(int i, int j) {
    if(i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] != 1){
        return;
    }
    pictureSize++;
    matrix[i][j] = 0;

    dfs(i-1, j);
    dfs(i+1, j);
    dfs(i, j-1);
    dfs(i, j+1);
}

int main() {
    cin >> m >> n;
    int pictureCount = 0, maxCount = 0;
    matrix.resize(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(matrix[i][j] != 1){
                continue;
            }
            dfs(i, j);
            pictureCount++;
            if(maxCount < pictureSize){
                maxCount = pictureSize;
            }
            pictureSize = 0;
        }

    }
    cout << pictureCount << endl;
    cout << maxCount;

    return 0;
}
