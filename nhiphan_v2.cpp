#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++) printf("0");
	for(int i=1;i<pow(2,a);i++){
		char s[21]="",s1[2]="";
		int k,num;
		num=i;
		while (num>0){
			k=num%2;
			num/=2;
			sprintf(s1,"%d",k);
			strcat(s,s1);
		}
		while (strlen(s)<=a) strcat(s,"0");
		if (!strstr(s,"111")){
		    printf("\n");
			for(int j=a-1;j>=0;j--) printf("%c",s[j]);
		}
			
	}
}