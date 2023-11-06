#include<stdio.h>
int k,n;
long long M[1000][1000];
long long C(int k, int n){
	if (k==0||k==n) M[k][n]=1;
	else if(M[k][n] == 0) 
	M[k][n] = (C(k,n-1) + C(k-1,n-1)) % 1000000007;
	return M[k][n];
}
int main(){
	scanf("%d %d",&k,&n);
	printf("%lld",C(k,n));
}
