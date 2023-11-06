#include <stdio.h>
int k,count = 0;
void move(int n,char A,char B,char C){
    if(n == 1){
        count++;
        printf("[%d]:\t %c -> %c\n",count,A,B);
    }else{
        move(n-1,A,C,B);
        move(1,A,B,C);
        move(n-1,C,B,A);
    }
}
int main(){
    scanf("%d",&k);
    move(k,'A','B','C');
}