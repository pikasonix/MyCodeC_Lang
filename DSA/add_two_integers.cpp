/* ADD BIGNUM */
#include<stdio.h>
#include<string.h>

// void strrev(char* str) {
//     char tmp;
//     for(int i=0, j=strlen(str)-1 ; i<j ; j--,i++){
//         tmp = str[i]; 
//         str[i] =str[j];
//         str[j]=tmp;
//     }
// }
int main(){
    char s1[21], s2[21];
    int rs[21], c1, c2;
    int i,j,m, cmax, sum;

    scanf("%s %s",s1,s2);
    c1 = strlen(s1);
    c2 = strlen(s2);
    if(c1<c2) cmax = c2; else cmax = c1;
    strrev(s1);
    strrev(s2);

    m=0;
    for(i=0;i<cmax;i++){
        if(c1==c2 || (i < c1 && i < c2))    sum = m+(s1[i]-48)+(s2[i]-48);
        else if(i >=c1)                     sum = m+(s2[i]-48);
        else if(i >=c2)                     sum = m+(s1[i]-48);
        rs[i] = sum%10;
        m = sum/10;
    }

    if(m){
        rs[i]=m;
        i++;
    }

    for(j=0;j<i;j++)    printf("%d", rs[i-j-1]);
}