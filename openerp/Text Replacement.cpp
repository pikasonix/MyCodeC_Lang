
#include<stdio.h>
#include<string.h>
int main(){
    char s1[1000],s2[1000],s[1000];
    fgets(s1,1000,stdin); s1[strlen(s1+1)]='\0';
    fgets(s2,1000,stdin); s2[strlen(s2+1)]='\0';
    fgets(s ,1000,stdin);  s[strlen(s+1)]='\0';
    char *pos, temp[1000];
    while ((pos = strstr(s,s1)) != NULL) {
        strcpy(temp,s);
        int index = pos-s;
        s[index] = '\0';
        strcat(s,s2);
        strcat(s, temp + index + strlen(s1));
    }
    printf("%s",s);
}
