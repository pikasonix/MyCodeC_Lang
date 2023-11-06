/* GIẢI PHƯƠNG TRÌNH BẬC 2 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc, char *argv[]){
    double A = atof(argv[1]);
    double B = atof(argv[2]);
    double C = atof(argv[3]);
    double Delta = B*B-4*A*C;
    if (Delta < 0) printf("Vo nghiem");
    if (Delta == 0) printf("x1=x2=%llf",-B/(2*A));
    if (Delta > 0) printf("x1=%llf  x2=%llf",(-B+sqrt(Delta))/(2*A),(-B-sqrt(Delta))/(2*A));
}
