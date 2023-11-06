#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void CopyByChar(FILE*f1,char*ptr){
    FILE*f2=fopen("output.txt","w");
    int c;
    while((c=fgetc(f1))!=EOF)
        fputc(c,f2);
    fclose(f2);
}
void CopyByLine(FILE*f1,char*ptr){
    FILE*f2=fopen("output.txt","w");
    while(fgets(ptr,201,f1)!=NULL)
        fputs(ptr,f2);
    fclose(f2);
}
void CopyByBlock(FILE*f1,char*ptr,int a){
    int num;
    FILE*f2=fopen("output.txt","w");
    while(!feof(f1)){
        num=fread(ptr,sizeof(char),100,f1);
        fwrite(ptr,sizeof(char),num,f2);
    }
    fclose(f2);
}
int main(int argc, char*argv[]){
    int a,b;
    char *ptr=(char*)malloc(200*sizeof(char));
    FILE *f1 = fopen(argv[1],"r");
    if(!f1){
        printf("Khong tim thay file!");
        return 1;
    }
    if(argc!=2){
        printf("Loi!");
        return 1;
    }
    while(b!=4){
        printf("Menu \n1.Copy by characters[1] \n2.Copy by line[2] \n3.Copy by block - optional size[3] \n4.Exit[4] \n-> ");
        scanf("%d",&b);
        fseek(f1,0,SEEK_SET);
        clock_t x,y;
        switch(b){
            case 1 :
                x=clock();
                CopyByChar(f1,ptr);
                y=clock();
                printf("Time: %lf\n",(double)(y-x)/1000);
                break;
            case 2 :
                x=clock();
                CopyByLine(f1,ptr);
                y=clock();
                printf("Time: %lf\n",(double)(y-x)/1000);
                break;
            case 3 :
                printf("size block: "); scanf("%d",&a);
                x=clock();
                CopyByBlock(f1,ptr,a);
                y=clock();
                printf("Time: %lf\n",(double)(y-x)/1000);
                break;
        }
    }
    free(ptr);
    fclose(f1);
}
