/* XẾP HẬU (DÙNG KỸ THUẬT ĐÁNH DẤU) */
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n,x[MAX];
int a[MAX]={0}; // mảng đánh dấu hàng đã bị kiểm soát (1 đã, 0 chưa)
int b[MAX]={0}; // mảng đánh dấu đường chéo dưới-trái -> trên-phải
int c[MAX]={0}; // mảng đánh dấu đường chéo dưới-phải -> trên-trái
void In(){
    for(int i=1;i<=n;i++)   printf("%d",x[i]);
    printf("\n"); 
}
void TRY(int k){
    for(int i=1;i<=n;i++)
        if(!a[i] && !b[k+i] && !c[k-i]){        // nếu ô [k][i] chưa đánh dấu
            x[k] = i;                           // thử đặt hậu vào i
            if(k == n) In();
                else{
                    a[i]=1; b[k+i]=1; c[k-i]=1; // đánh dấu đã bị kiểm soát
                    TRY(k+1);
                    a[i]=0; b[k+i]=0; c[k-i]=0; // bỏ đánh dấu 
                }
        }
}
int main(){
    scanf("%d",&n);
    TRY(1);
}