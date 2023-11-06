/* ĐỔI SANG CHỮ HOA */
#include<stdio.h>
#include<ctype.h>
int main(int argc, char *argv[]){
    if (argc!=2) printf("Loi, hay nhap theo cu phap: .\\uconvert file");
    if (argc==2){
        FILE *f1 = fopen(argv[1],"r+");
        if (!f1){
            printf("Loi, khong tim thay file %s",argv[1]);
            return 1;
        }
        int c;
        while(c = fgetc(f1) != EOF){
            if (c >= 'a' && c <= 'z') c-=32;
            fputc(c, f1);
        }
        printf("Da copy xong");
        fclose(f1); 
    }
}
