/* READ FILE */
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct phoneaddress{
    char name[MAX];
    char tel[MAX];
    char email[MAX];
}phone;
void read(FILE*f,phone*ptr){
    int i=0;
    while((int*)fread(ptr,sizeof(phone),1,f)!=NULL){
        printf("%2d %20s %10s %25s\n",i+1,ptr->name,ptr->tel,ptr->email);
        i++;
    }
}
int main(int argc, char*argv[]){
    if(argc!=2){
        printf("Loi! ./readfile chosen file!");
        return 1;
    }
    FILE *f=fopen(argv[1],"rb");
    phone *ptr;
    if(f==NULL){
        printf("Khong mo duoc file: %s !\n",argv[1]);
        return 1;
    }
    ptr=(phone*)malloc(1*sizeof(phone));
    read(f,ptr);
    fclose(f);
    free(ptr);
}
