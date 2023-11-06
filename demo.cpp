/* XẾP HẬU (DÙNG KỸ THUẬT ĐÁNH DẤU) */
#include<stdio.h>
#include<stdlib.h>

int col[101]={0};
int row[101]={0};
int cross1[200]={0};
int cross2[200]={0};
int n;
int output=0;

void TRY(int k){
    while (col[k]) {k++; if (k>=n) output++;}
        for (int i=1;i<=n;i++){
            if(!row[i] && !cross1[k+i-1] && !cross2[n-k+i]){        // nếu ô [k][i] chưa đánh dấu
                if(k == n) output++;
                    else{
                        row[i]++; cross1[k+i-1]++; cross2[n-k+i]++; // đánh dấu đã bị kiểm soát
                        TRY(k+1);
                        row[i]--; cross1[k+i-1]--; cross2[n-k+i]--; // bỏ đánh dấu 
                    }
            }
        }
}

int main(){
    int a;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                scanf("%d",&a);
                col[i]+=a;
                row[j]+=a;
                cross1[i+j-1]+=a;
                cross2[n-i+j]+=a;
            }
        }
    TRY(1);
    printf("%d",output);
}