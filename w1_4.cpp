/* COPY FILE */
#include<stdio.h>

int main(int argc, char *argv[]){
    if (argc!=3) printf("Loi, hay nhap theo cu phap: .\\w1_4 fileInput fileOutput");
    if (argc==3){
        FILE *f1, *f2;
        f1 = fopen(argv[1],"r");
	    f2 = fopen(argv[2],"w");
        if (!f1){
            printf("Loi, khong tim thay file %s",argv[1]);
            return 1;
        }
        char c;
        while(!feof(f1)){
            c=fgetc(f1);
            if (c != EOF) fputc(c, f2);
        }
        printf("Da copy xong");
        fclose(f1); fclose(f2);
    }
}
