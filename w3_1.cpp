/* a1x1 + a2x2 + . . . + anxn = m */
#include<stdio.h>
#include<stdlib.h>
#define MAX 1002 // n(max) = 1000
int m,n,a[MAX],S[MAX]={0},x[MAX]={0},sum=0;
void In(){
	for (int i=1;i<=n;i++)  printf("%d ",x[i]);
	printf("\n");
}
int check(int i,int k){
	if (k==n) return(sum+i*a[k]==m);
	return 1;
}
void Solution(int k){
	for (int i=1;i<=m-sum-S[k+1];i++)
		if (check(i,k)){
			x[k]=i;
			sum+=i*a[k];
			if (k==n) In();
				else Solution(k+1);
			sum-=i*a[k];
		}
}
int main(){
    scanf("%d %d",&m,&n);
    for (int i=1;i<=n;i++)  scanf("%d",&a[i]);
    for (int i=n;i>=1;i--)  S[i]=a[i]+S[i+1]; 
    Solution(1);
}
