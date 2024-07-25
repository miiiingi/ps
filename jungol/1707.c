#include<stdio.h>
#include<string.h>
int main(){
    int n, number = 1, x = 1, y = 1;
    scanf("%d", &n);

    int matrix[n+2][n+2];
    memset(matrix, 0, sizeof(matrix));

    for (int i = 0; i < n + 2; i++)
    {
        if (i == 0 || i == n + 1)
        {
            for (int j = 0; j < n + 2; j++)
            {
                matrix[i][j] = 1;
            }
        } else {
            matrix[i][0] = 1;
            matrix[i][n + 1] = 1;
        }
    }
    while(number <= n*n){
        for (;;)
        {
            if(matrix[x][y] != 0){
                y--;
                x++;
                break;
            }
            matrix[x][y] = number;
            y++;
            number++;
        }
        for (;;)
        {
            if(matrix[x][y] != 0){
                y--;
                x--;
                break;
            }
            matrix[x][y] = number;
            x++;
            number++;
        }
        for (;;)
        {
            if(matrix[x][y] != 0){
                y++;
                x--;
                break;
            }
            matrix[x][y] = number;
            y--;
            number++;
        }
        for (;;)
        {
            if(matrix[x][y] != 0){
                y++;
                x++;
                break;
            }
            matrix[x][y] = number;
            x--;
            number++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}