/* SUDOKU (DÙNG KỸ THUẬT ĐÁNH DẤU) */
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n,x[MAX][MAX],hang_vuong=1,cot_vuong=1,point=0;
int hang[MAX][MAX]; // mảng đánh dấu hàng đã bị kiểm soát (1 đã, 0 chưa)
int cot[MAX][MAX]; // mảng đánh dấu các số trong cột ([4][5]==1 -> cột 4 thì đã có số 5)
int vuong[MAX][MAX]; // mảng đánh dấu các số trong ô vuông 3x3
FILE *f = fopen("input.txt","w");
void In(){
    
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++)   
            fprintf(f,"%d ",x[i][j]);
        fprintf(f,"\n");
    }
    fprintf(f,"\n"); 

}

void TRY(int r, int c){
    for(int i=1;i<=9;i++){
        // fprintf(f,"%d %d\n",r,c);
         
        hang_vuong=(r+2)/3;
        cot_vuong=(c+2)/3;
        if(!hang[r][i] && !cot[c][i] && !vuong[3*(hang_vuong-1)+cot_vuong][i]){
            x[r][c] = i;
            hang[r][i]++; cot[c][i]++; vuong[3*(hang_vuong-1)+cot_vuong][i]++;
            In();
            // printf("%d ",i); point++; if (point%9==0) printf("\n"); //
            if(r == 9 && c == 9) In();
                else{
                    if(c == 9){
                        TRY(r+1,1);
                         hang[r][i]--; cot[c][i]--; vuong[3*(hang_vuong-1)+cot_vuong][i]--;
                    }
                        else {
                            TRY(r,c+1);
                            hang[r][i]--; cot[c][i]--; vuong[3*(hang_vuong-1)+cot_vuong][i]--;
                        }
                }
        }
    }
}
int main(){
    // Khởi tạo mảng
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cot[i][j] = 0;
            hang[i][j] = 0;
            vuong[i][j] = 0;
        }
    }
    TRY(1,1);
    fclose(f);
}