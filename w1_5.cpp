/* CHƯƠNG TRÌNH NỐI TẬP TIN */
#include<stdio.h>

int main(int argc, char *argv[]){
    if (argc!=3) printf("Loi, hay nhap theo cu phap: .\\w1_5 file1 file2");
    if (argc==3){
        FILE *f1, *f2;
        f1 = fopen(argv[2],"r");
	    f2 = fopen(argv[1],"a");
        if (!f1){
            printf("Loi, khong tim thay file %s",argv[1]);
            return 1;
        }
        fputc('\n', f2);
        char c;
        while(!feof(f1)){
            c=fgetc(f1);
            if (c != EOF) fputc(c, f2);
        }
        printf("Da xong");
        fclose(f1); fclose(f2);
    }
}
