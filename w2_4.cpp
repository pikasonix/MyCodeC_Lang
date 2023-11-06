#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct info{
   int  STT;
   int  MSSV;
   char NAME[20];
   char SDT[10];
   double diemthi;
}sinhvien;
 
void NhapDiem(FILE*f1,sinhvien*SV,int n){
    FILE*f2;
    f2=fopen("bangdiem.txt","w");
    int i=0;
    while(fscanf(f1,"%d %d %s %s",&(SV+i)->STT,&(SV+i)->MSSV,(SV+i)->NAME,&(SV+i)->SDT)!=EOF){
        printf("Nhap diem cho %d: ",SV[i].MSSV); scanf("%lf",&(SV+i)->diemthi);
        i++;
    }
    fprintf(f2,"%-5s %-10s %-20s %-12s %-5s\n","STT","MSSV","HO TEN","SDT","DIEM");
    for(int j=0;j<n;j++)
        fprintf(f2,"%-5d %-10d %-20s %-12s %-5.2lf\n",(SV+j)->STT,(SV+j)->MSSV,(SV+j)->NAME,(SV+j)->SDT,(SV+j)->diemthi);
    fclose(f2);
}
void ThemSV(sinhvien*SV,int line,int add){
    FILE*f2;
    f2=fopen("bangdiem.txt","a+");
    for(int i=line-add;i<line;i++){
        (SV+i)->STT=i+1;
        printf("Sinh vien thu %d:\n",(SV+i)->STT);
        printf("MSSV: "); scanf("%d",&(SV+i)->MSSV);
        printf("NAME: "); scanf("%s",(SV+i)->NAME);
        printf("SDT:  "); scanf("%s",(SV+i)->SDT);
        printf("DIEM: "); scanf("%lf",&(SV+i)->diemthi);
        fprintf(f2,"%-5d %-10d %-20s %-12s %-5.2lf\n",(SV+i)->STT,(SV+i)->MSSV,(SV+i)->NAME,(SV+i)->SDT,(SV+i)->diemthi);
    }
    fclose(f2);
}
int main(int argc, char*argv[]){
    int a,b;
    int add;
    char m[MAX];
    sinhvien *SV;
    int i=0,line=0;
    FILE *f1 = fopen(argv[1],"r"); 
    if(!f1){
        printf("Khong tim thay file!");
        return 1;
    }
    if(argc!=2){
        printf("Loi!");
        return 1;
    }
    FILE *f = fopen(argv[1],"r"); 
    while(fgets(m,200,f)!=NULL) line++; fclose(f);

    SV=(sinhvien*)calloc(line+3,sizeof(sinhvien)); 
    while(b!=3){
        printf("Menu \n1.Nhap diem sinh vien[1] \n2.Nhap them sinh vien[2] \n3.Exit[3]\n -> ");
        scanf("%d",&b);
        switch(b){
            case 1:
                NhapDiem(f1,SV,line);
                break;
            case 2:
                printf("So SV them: "); scanf("%d",&add);
                SV=(sinhvien*)realloc(SV,add+1);
                line+=add;
                ThemSV(SV,line,add);
                break;
        }
    }
    free(SV);
    fclose(f1);
}
