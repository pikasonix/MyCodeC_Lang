/* XẾP HẬU (DÙNG KỸ THUẬT ĐÁNH DẤU) */
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n,x[MAX][MAX];
int b[MAX]={0}; // mảng đánh dấu đường chéo dưới-trái -> trên-phải
int c[MAX]={0}; // mảng đánh dấu đường chéo dưới-phải -> trên-trái
void In(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",x[j][i]);
        }
        printf("\n"); 
    }  
    printf("\n");
}
void TRY(int k){
    for(int i=1;i<=n;i++)
        for(int j=0;j<n;j++)
            if(!b[k+i+j] && !c[k-i-j]){        // nếu ô [k][i] chưa đánh dấu
                x[k][i+j] = 1;                           // thử đặt hậu vào i
                if(k == n) In();
                    else{
                        b[k+i+j]=1; c[k-i-j]=1; // đánh dấu đã bị kiểm soát
                        TRY(k+1);
                        b[k+i+j]=0; c[k-i-j]=0; // bỏ đánh dấu 
                    }
                x[k][i] = 0;
            }
}
int main(){
    scanf("%d",&n);
    TRY(1);
}