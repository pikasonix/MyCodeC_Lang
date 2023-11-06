#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* subStr(char*s1,int offset,int number){
   char*sub=(char*)calloc(200,sizeof(char));
   strcpy(sub,s1);
   if(offset<0||number<0){
       printf("Enter: offset > 0 and number > 0");
       return NULL;
   }
   sub[offset+number] ='\0';
   return sub+offset; 
}
int main(){
   char *ptr;
   ptr=(char*)calloc(200,sizeof(char));
   int a,b;
   printf("String: ");          fgets(ptr,201,stdin);
   printf("offset: ");   scanf("%d",&a);
   printf("number: ");   scanf("%d",&b);
   printf("%s",subStr(ptr,a,b));
   free(ptr);
}
