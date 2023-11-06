/* FILE MERGE */
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
    char name[MAX];
    char tel[MAX];
    char email[MAX];
}phone;
int main(int argc, char*argv[]){
    FILE*f,*f1,*f2;
    phone*ptr=(phone*)malloc(1*sizeof(phone));
    if(argc!=4){
        printf("Loi! ./filesplit file number file1 file2");
        return 1;
    }
    f1=fopen(argv[1],"rb");
    f2=fopen(argv[2],"rb");
    f=fopen(argv[3],"wb");
    if(!f1||!f2){
        printf("Khong tim thay file!");
        return 1;
    }
    while((int*)fread(ptr,sizeof(phone),1,f1)!=NULL)
        fwrite(ptr,sizeof(phone),1,f);
    fclose(f1);
    while((int*)fread(ptr,sizeof(phone),1,f2)!=NULL)
        fwrite(ptr,sizeof(phone),1,f);
    fclose(f); fclose(f2);
    free(ptr);
}
