/* ĐỔI SANG CHỮ HOA */
#include<stdio.h>
#include<ctype.h>
int main(int argc, char *argv[]){
    if (argc!=2) printf("Loi, hay nhap theo cu phap: .\\w1_6 file");
    if (argc==2){
        FILE *f1, *f2;
        f1 = fopen(argv[1],"r");
	    f2 = fopen("output.txt","w");
        if (!f1){
            printf("Loi, khong tim thay file %s",argv[1]);
            return 1;
        }
        char c;
        while(!feof(f1)){
            c=fgetc(f1);
            if (c != EOF) fputc(toupper(c), f2);
        }
        fclose(f1); fclose(f2);
        f1 = fopen(argv[1],"w");
	    f2 = fopen("output.txt","r");
        while(!feof(f2)){
            c=fgetc(f2);
            if (c != EOF) fputc(c, f1);
        }
        printf("Da xong");
        fclose(f1); fclose(f2);
    }
}
