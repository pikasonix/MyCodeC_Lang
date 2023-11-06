#include<stdio.h>
#include<stdlib.h>
#define MAX 256
int main(){
    FILE*f1,*f2,*f;
    int a,b;
    int irc;
    char *ptr=(char*)malloc(MAX*sizeof(char));
    f1=fopen("vnedict.txt","r");
    f2=fopen("vnedict.dat","wb");
    f =fopen("vnedict.dat","rb");
    if(!f1){
        printf("Khong tim thay file!");
        return 1;
    }
    while(fgets(ptr,MAX,f1)!=NULL)
        fwrite(ptr,MAX*sizeof(char),1,f2);
    printf("Dau, cuoi: "); scanf("%d %d",&a,&b);
    while(b<a||a<0||b<0){
        printf("Loi hay nhap: 0 < dau < cuoi. Nhap lai dau, cuoi: "); scanf("%d %d",&a,&b);
    }
    if(fseek(f,(b-1)*MAX*sizeof(char),SEEK_SET)!=0){
        printf("loi truy cap\n");
        return 1;
    }
    irc=ftell(f);
    rewind(f);
    if(fseek(f,a*MAX*sizeof(char),SEEK_SET)!=0){
        printf("loi truy cap\n");
        return 1;
    }
    while(ftell(f)!=irc){
        fread(ptr,MAX*sizeof(char),1,f);
        printf("%s \n",ptr);
    }
    fclose(f2); fclose(f1); fclose(f);
    free(ptr);
}