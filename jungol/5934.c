#include<stdio.h>
int main(){
    int n, upper, bottom;
    scanf("%d", &n);
    upper = n / 2 + 1;
    bottom = n - upper;

    if(n % 2 == 0 || n == 0 || n >= 100){
        printf("INPUT ERROR!");
    } else {
        for(int i = 0; i < upper; i++){
            for(int j=0; j<i; j++){
                printf(" ");
            }
            for(int k=0; k<upper-i; k++){
                printf("*");
            }
            printf("\n");
        }

        for(int i = bottom; i > 0; i--){
            for(int j=0; j<bottom; j++){
                printf(" ");
            }
            for(int k=0; k<=upper-i; k++){
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}