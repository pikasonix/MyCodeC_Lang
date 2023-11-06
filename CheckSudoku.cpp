/* SUDOKU (DÙNG KỸ THUẬT ĐÁNH DẤU) */
#include<stdio.h>

#define MAX 10
int row[MAX][MAX]; // mảng đánh dấu hàng đã bị kiểm soát (1 đã, 0 chưa)
int col[MAX][MAX]; // mảng đánh dấu các số trong cột ([4][5]==1 -> cột 4 thì đã có số 5)
int grid[MAX][MAX]; // mảng đánh dấu các số trong ô vuông 3x3


int main(){
    int n,a;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<=9;j++)
            for (int k=0;k<=9;k++){
                row[j][k]=0;
                col[j][k]=0;
                grid[j][k]=0;
            }
        int check=1;
        for (int j=0;j<9;j++)
            for (int k=0;k<9;k++){
                scanf("%d",&a); 
                if (a<1 || a>9) check = 0;
                else {
                    row[j][a]++;
                    col[k][a]++;
                    grid[3*(j/3)+k/3+1][a]++;
                    if (row[j][a]>1 || col[k][a]>1 || grid[3*(j/3)+k/3+1][a]>1) {check=0; printf("|%d|",a);}
                }
            }
        printf("%d\n",check);             
    }      
}