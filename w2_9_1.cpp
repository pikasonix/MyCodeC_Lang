/* FILE SPLIT */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
typedef struct{
    char name[MAX];
    char tel[MAX];
    char email[MAX];
}phone;
int main(int argc, char*argv[]){
    int a;
    long b;
    FILE*f1,*fo1,*fo2;
    phone*p;
    if(argc!=5){
        printf("Loi! ./filesplit file number file1 file2");
        return 1;
    }
    a=atoi(argv[2]);
    p=(phone*)malloc(a*sizeof(phone));
    f1=fopen(argv[1],"rb");
    if(!f1){
        printf("Khong tim thay file!");
        return 1;
    }
    fo1=fopen(argv[3],"wb");
    fo2=fopen(argv[4],"wb");
    fread(p,sizeof(phone),a,f1);
    fwrite(p,sizeof(phone),a,fo1);
    while((int*)fread(p,sizeof(phone),1,f1)!=NULL)
        fwrite(p,sizeof(phone),1,fo2);
    fclose(f1); fclose(fo1); fclose(fo2);
    free(p);
}