#include<stdio.h>

typedef struct info{
   int  STT;
   int  MSSV;
   char NAME[20];
   char SDT[10];
   double diemthi;
}sinhvien;

int main(int argc, char*argv[]){
    sinhvien SV[100];
    FILE *f1,*f2;
    
    f1=fopen(argv[1],"r");
    f2=fopen("bangdiem.txt","w");
    if(!f1){
        printf("Khong tim thay file!");
        return 1;
    }
    if(argc!=2){
        printf("Loi!");
        return 1;
    }
    int i=0;
    while(fscanf(f1,"%d %d %s %s",&SV[i].STT,&SV[i].MSSV,SV[i].NAME,SV[i].SDT)!=EOF){
        printf("Nhap diem cho %d: ",SV[i].MSSV);
        scanf("%lf",&SV[i].diemthi);
        i++;
    }
    fprintf(f2,"%-5s %-10s %-20s %-12s %-5s\n","STT","MSSV","HO TEN","SDT","DIEM");
    for(int j=0;j<i;j++) 
        fprintf(f2,"%-5d %-10d %-20s %-12s %-5.2lf\n",SV[j].STT,SV[j].MSSV,SV[j].NAME,SV[j].SDT,SV[j].diemthi);
    fclose(f1); fclose(f2);
}
