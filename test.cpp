/* SUDOKU (DÙNG KỸ THUẬT ĐÁNH DẤU) */
#include<stdio.h>

#define MAX 10
int row[MAX][MAX]; // mảng đánh dấu hàng đã bị kiểm soát (1 đã, 0 chưa)
int col[MAX][MAX]; // mảng đánh dấu các số trong cột ([4][5]==1 -> cột 4 thì đã có số 5)
int grid[MAX][MAX]; // mảng đánh dấu các số trong ô vuông 3x3
int a[MAX][MAX];

void In(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)   
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n"); 

}

int check(int v, int i, int j)
{
	
	return row[i][v]==0 && col[j][v] ==0 && grid[3*((i-1)/3)+(j-1)/3+1][v]==0;	
}

void TRY(int r, int c){
    if (a[r][c]){
        if(r == 9 && c == 9) In();
        if (c<9) TRY(r,c+1); else TRY(r+1,c);
        return;
    } else {
        for(int i=1;i<=9;i++){
            if(check(i,r,c)){
                a[r][c] = i;
                if(r == 9 && c == 9) In();
                    else{
                        row[r][i]++; col[c][i]++; grid[3*((r-1)/3)+(c-1)/3+1][i]++;
                        if(c == 9){
                            TRY(r+1,1);
                            row[r][i]--; col[c][i]--; grid[3*((r-1)/3)+(c-1)/3+1][i]--;
                        } else{
                            TRY(r,c+1);
                            row[r][i]--; col[c][i]--; grid[3*((r-1)/3)+(c-1)/3+1][i]--;
                        }
                    }
            }
        }
    }
    
}

int main(){
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++){
            row[i][j]=0;
            col[i][j]=0;
            grid[i][j]=0;
        }

    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++){
            scanf("%d",&a[i][j]); 
            row[i][a[i][j]]++;
            col[j][a[i][j]]++;
            grid[3*((i-1)/3)+(j-1)/3+1][a[i][j]]++;
        }  
    TRY(1,1);               
}