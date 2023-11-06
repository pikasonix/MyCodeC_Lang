#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int id;
    struct Node* next; 
    struct Node* prev; 
}Node;

Node *head, *tail;

Node* makeNode(int k){
    Node*p= (Node*)malloc(sizeof(Node));
    p->id = k;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void initQueue(){
    head = NULL;    tail = NULL;
}

int queueEmpty() {
    return head == NULL && tail == NULL;
}

void pushQueue(Node* p){
    if (queueEmpty()){
        head = p;
        tail = p;
    }else{
        tail->next = p;
        tail = p;
    }
}

int popQueue(){
    Node* p = head;
    head = p->next;
    if (head == NULL) tail = NULL;
    return p->id;
}

int main(){
    int k;
    char s[100];
    initQueue();
    while (1){
        scanf("%s",s);
        if (strcmp(s,"PUSH")==0){
            scanf("%d",&k);
            pushQueue(makeNode(k));
        }
        else if (strcmp(s,"POP")==0){
            if(queueEmpty()) printf("NULL\n");
            else printf("%d\n",popQueue());
        }
        else if (strcmp(s,"#")==0){
            return 0;
        }
    }  
}
