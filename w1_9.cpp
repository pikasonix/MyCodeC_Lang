/* ĐIỀN VÀO CUỐI FILE CÁC KÝ TỰ ĐẦU TIÊN CỦA CÁC DÒNG */
#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[]){
    if (argc!=2) printf("Loi, hay nhap theo cu phap: .\\w1_9 file");
    if (argc==2){
        FILE *f1;
        f1 = fopen(argv[1],"r+");
        if (!f1){
            printf("Loi, khong tim thay file %s",argv[1]);
            return 1;
        }
        char s[80]="";
        char s1[256];
        while(!feof(f1)){
            fgets(s1,256,f1); 
            strncat(s,s1,1);
        }
        fprintf(f1,"\n%s",s);
        printf("Da xong");
        fclose(f1);
    }
}
