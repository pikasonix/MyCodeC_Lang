/* MÃ HOÁ CAESAR */
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
    if (argc!=4) printf("SyntaxError: invalid syntax! .\\w1_7 fileInput offset fileOutput");
    if (argc==4){
        FILE *f1, *f2;
        f1 = fopen(argv[1],"r");
	    f2 = fopen(argv[3],"w");
        int offset = atof(argv[2]);
        if (!f1){
            printf("Cannot open file %s\n",argv[1]);
            return 1;
        }
        int option,advanced;
        printf("Encrypt[1] Decrypt[2] \n -> "); scanf("%d",&option);
        printf("Advanced options: Yes[1] No[0] \n -> "); scanf("%d",&advanced);
        if (option==2) offset=-offset;
        if (!advanced){
            char c;
            while(!feof(f1)){
                c=fgetc(f1);
                if (c != EOF) fputc(c+offset, f2);
            }
        } else {
            char c;
            while(!feof(f1)){
                c=fgetc(f1);
                if (c != EOF && (c<'A' || (c>'Z' && c<'a') || c>'z')) fputc(c+offset, f2);
                    else if (c != EOF && c>='A' && c<='Z') fputc((c+offset-'A')%26+'A',f2); 
                        else if (c != EOF) fputc((c+offset-'a')%26+'a',f2); 
            }
        }       
        printf("Da xong");
        fclose(f1); fclose(f2);
    }
}
