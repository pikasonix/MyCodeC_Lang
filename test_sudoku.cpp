#include<stdio.h>
#define MAX 10
int a[MAX][MAX], temp[MAX][MAX];  
int row[MAX][MAX];  
int col[MAX][MAX];  
int grid[3][3][MAX]; 
int count;

void In(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	printf("\n");	
}

void TRY(int r,int c){
	if(temp[r][c]>0){
		if(r==8 && c==8) {In(); count++;}
		else{
			if(c==8) TRY(r+1,0);
			else TRY(r,c+1);
		}
		return;
	} else {
		for(int i=1;i<=9;i++){
			if(!row[r][i] && !col[c][i] && !grid[r/3][c/3][i]){
				a[r][c]=i; 
                row[r][i]=1; col[c][i]=1; grid[r/3][c/3][i]=1;
				if(r==8 && c==8) {In(); count++;}
                    else{
                        if(c==8) TRY(r+1,0);
                            else TRY(r,c+1);
                    }
				row[r][i]=0; col[c][i]=0; grid[r/3][c/3][i]=0;
			}
		}
	}
}

int main(){
	for(int i=0;i<9;i++)
		for( int j=0;j<9;j++){
				scanf("%d",&a[i][j]);
				temp[i][j]=a[i][j];
                row[i][a[i][j]]++;
				col[j][a[i][j]]++;
				grid[i/3][j/3][a[i][j]]++;
			}
	TRY(0,0);
    printf("%d",count);
}