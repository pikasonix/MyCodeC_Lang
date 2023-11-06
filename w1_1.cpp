/* SINH CÂU VĂN TỰ ĐỘNG */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MAX 20      //Số phần tử tối đa của mảng
int main(){
    /* Mảng các input */
    char article[MAX][20]={"the", "a", "one", "some", "any"};
    char noun[MAX][20]={"boy", "girl", "dog", "town", "car"};
    char verb[MAX][20]={"drove", "jumped", "ran", "walked", "skipped"};
    char prep[MAX][20]={"to", "from", "over", "under", "on"};
    /* Kiểm tra số lượng phần tử các mảng */
    int MAX_a=0,MAX_n=0,MAX_v=0,MAX_p=0; 
    while(strlen(article[MAX_a])!=0) MAX_a++;
    while(strlen(noun[MAX_n])!=0) MAX_n++;
    while(strlen(verb[MAX_v])!=0) MAX_v++;
    while(strlen(prep[MAX_p])!=0) MAX_p++;
    /* Sinh câu ngẫu nhiên */
    int n;      
    printf("The number of sentences: "); scanf("%d",&n);
    time_t t;       // random
    srand((unsigned) time(&t));
    char s[20];
    for (int i=0;i<n;i++){
        strcpy(s,article[rand() % MAX_a]);
        s[0]-=32;
        printf("%s %s %s %s %s.\n", s, noun[rand() % MAX_n],verb[rand() % MAX_v],article[rand() % MAX_a],noun[rand() % MAX_n]);
    }
}