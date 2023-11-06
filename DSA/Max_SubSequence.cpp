#include<stdio.h>
int n;
int maxSubSeq(int a[]){
    int sum[n+1]; 
    sum[1] = a[1]; 
    int max = sum[1]; 

    for(int i=2;i<=n;i++){
        if (sum[i-1] > 0)    sum[i] = sum[i-1] + a[i];
            else sum[i] = a[i]; 
        if (max < sum[i])    max = sum[i];
    }
    return max; 
}

int main(){
    scanf("%d",&n); 
    int a[n]; 
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]); 
    printf("%d",maxSubSeq(a)); 
}