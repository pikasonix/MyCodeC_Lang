#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int c;
    struct Node* next;
}Node;

Node* top;

Node* makeNode(int x){
    Node* p = (Node*)malloc(sizeof(Node));
    p->c = x; p->next = NULL;
    return p;
}

void initStack(){
    top = NULL;
}

int stackEmpty(){
    return top == NULL;
}

void push(int k){
    Node* p = makeNode(k);
    p->next = top; 
    top = p;
}

int pop(){
    int x = top->c;
    Node* tmp = top; 
    top = top->next; 
    free(tmp);
    return x;
}
int main(){
    int k;
    char s[100];
    while (1){
        scanf("%s",s);
        if (strcmp(s,"PUSH")==0){
            scanf("%d",&k);
            push(k);
        }
        else if (strcmp(s,"POP")==0){
            if(stackEmpty()) printf("NULL\n");
            else printf("%d\n",pop());
        }
        else if (strcmp(s,"#")==0){
            return 0;
        }
    }  
}
