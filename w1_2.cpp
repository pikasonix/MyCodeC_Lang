/* TÍNH EXP */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long long giaithua(int n){
    if(n == 0 || n == 1) return 1;
    return n*giaithua(n-1);
}
int main(int argc, char *argv[]){
    if (argc==3) {
        double a = atof(argv[2]);
        printf("%llf",exp(a));
    }
    if (argc==4) {
        double exp;
        double a = atof(argv[2]);
        double delta = atof(argv[3]);
        double e=1;
        int n=0;
        while(e >= delta){
            e = pow(float(a),n)/giaithua(n); 
            exp += e;
            n++;
        }
        printf("%llf",exp);
    }  
}
