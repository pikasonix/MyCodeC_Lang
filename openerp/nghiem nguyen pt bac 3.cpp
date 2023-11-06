#include<stdio.h>
#define MAX 10000
int main(){
    int a,b,c,n[2][3];
    int j=0;
    scanf("%d %d %d",&a,&b,&c);
    for (int i=-MAX;i<MAX;i++)
        if (i*i*i+a*i*i+b*i+c==0){
            n[j]=i;
            j++;
        }
    if (j==0) printf("NO SOLUTION");
    if (j==1) 
    /* giải bằng ma trận */
}
