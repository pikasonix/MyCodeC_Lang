#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
typedef struct data{
    char model[MAX];
    char memory[MAX];
    double size;
    double price;
}Phone;
int ImportFromText(FILE*f1,Phone*p){
    int i=0;
    FILE*f2=fopen("PhoneDB.dat","wb");
    while(fscanf(f1,"%s %s %lf %lf",p->model,p->memory,&(p->size),&(p->price))!=EOF){ 
        fwrite(p,sizeof(Phone),1,f2);
        i++;
    }
    fclose(f2);
    return i;
}
void ImportFromDB(int n){
    Phone*k=(Phone*)malloc(n*sizeof(Phone));
    int b;
    int i;
    FILE*f=fopen("PhoneDB.dat","rb");
    while(b!=3){
        int start, end;
        printf("\n1.In toan bo.\n2.In 1 phan.\n3.Exit\n");
        scanf("%d",&b);
        switch(b){
            case 1:
                printf("%-25s %-7s %-15s %-15s\n","Model","Memory","Size","Price");
                while((int*)fread(k,sizeof(Phone),1,f)!=NULL)
                    printf("%-25s %-7s %-14.1lf %-16.1lf \n",k->model,k->memory,k->size,k->price);
                break;
            case 2:
                printf("Dau, cuoi: ");
                scanf("%d %d",&start,&end);
                if(fseek(f,(start-1)*sizeof(Phone),SEEK_SET)!=0){
                    printf("Fseek failed!\n");
                    return;
                }
                fread(k,sizeof(Phone),end-start+1,f);
                for(i=0;i<end-start+1;i++)
                    printf("%-25s%-7s%-14.1lf%-16.1lf\n",k[i].model,k[i].memory,k[i].size,k[i].price);
                break;
        }
    }
    fclose(f);
}
void PrintAll(Phone*p,int n){
    FILE*f=fopen("PhoneDB.dat","rb");
    int i=1;
    int c;
    printf("%-25s %-7s %-15s %-15s\n","Model","Memory","Size","Price");
    while((int*)fread(p,sizeof(Phone),1,f)!=NULL){
        printf("%-25s %-7s %-14.1lf %-16.1lf \n",p->model,p->memory,p->size,p->price);
        i++;
    } 
    fclose(f);
}
void Search(int n){
    FILE*f=fopen("PhoneDB.dat","rb");
    Phone*x=(Phone*)calloc(n,sizeof(Phone));
    int i,j;
    char*b=(char*)calloc(MAX,sizeof(char));
    printf("Model: "); scanf("%s",b);
    printf("%s\n",b);
    printf("%-25s %-7s %-15s %-15s\n","Model","Memory","Size","Price");
    fread(x,sizeof(Phone),n,f);
    for(i=0;i<n;i++){
        if(strstr((x+i)->model,b)!=NULL)
        printf("%-25s %-7s %-14.1lf %-16.1lf \n",(x+i)->model,(x+i)->memory,(x+i)->size,(x+i)->price);
    } 
    free(b);
    free(x);
    fclose(f);
}
int main(){
    FILE*f1;
    f1=fopen("PhoneDB.txt","r");
    if(!f1){
        printf("Khong tim thay file!");
        return 1;
    }
    int i;
    int m,n;
    Phone*p;
    p=(Phone*)malloc(100*sizeof(Phone));
    while(m!=5){
        printf("\nMenu\n1.Import Database from text file.\n2.Import from Database.\n3.Print all Database.\n4.Search for Phone Model.\n5.Exit.\n-> ");
        scanf("%d",&m);
        switch(m){
            case 1 :
                n=ImportFromText(f1,p);
                rewind(f1);
                break;
            case 2 :
                ImportFromDB(n);
                break;
            case 3 :
                PrintAll(p,n);
                break;
            case 4 :
                Search(n);
                break;
            case 5 :
                break;
        }
    }
    free(p);
    fclose(f1);
}

