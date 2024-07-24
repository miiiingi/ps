#include<stdio.h>
int main(){
    int n, number = 0;
    scanf("%d", &n);
    if (n < 0 || n >= 50 || n % 2 == 0)
    {
        printf("INPUT ERROR!");
    } else {
        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = 0; i < j * 2 + 1; i++)
            {
                if (i != j * 2)
                {
                    printf("%d ", number);
                } else {
                    printf("%d", number);
                }

            }
            printf("\n");
            number++;
            for (int i = 0; i < number * 2; i++)
            {
                printf(" ");
            }
        }
    }
    return 0;
}