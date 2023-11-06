#include<stdio.h>
int main(){
    int n,k,m;
    scanf("%d %d",&n,&k);
    int a[n][k];
    for (int i=0;i<n;i++)
        for (int j=0;j<k;j++)
            scanf("%d",&a[i][j]);
            
    scanf("%d %d",&k,&m);
    int b[k][m];
    for (int i=0;i<k;i++)
        for (int j=0;j<m;j++)
            scanf("%d",&b[i][j]);
    for (int i=0;i<n;i++){
        for (int t=0;t<m;t++){
            int sum=0;
            for (int j=0;j<k;j++){
                sum+=a[i][j]*b[j][t];
            }
            printf("%d ",sum);
        }
        printf("\n");
        
    }
}
