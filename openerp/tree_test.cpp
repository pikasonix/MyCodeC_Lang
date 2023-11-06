#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* parent;
    struct Node* leftMostChild;
    struct Node* rightSibling;
} Node;
Node* root;

Node* find(Node* r, int u) {
    if (r == NULL) return NULL;
    if (r->id == u) return r;
    Node* p = r->leftMostChild;
    while (p != NULL) {
        Node* q = find(p, u);
        if (q != NULL) return q;
        p = p->rightSibling;
    }
    return NULL;
}

Node* makeNode(int u,int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = u;
    p->parent = find(root,v);
    p->leftMostChild = NULL;
    p->rightSibling = NULL;
    return p;
}

Node* addLast(Node* p, int u, int v) {
    if (p == NULL) return makeNode(u,v);
    p->rightSibling = addLast(p->rightSibling,u,v);
    return p;
}

void Insert(int u, int v) {
    Node* r = find(root, v);
    if (r == NULL) return;
    r->leftMostChild = addLast(r->leftMostChild,u,v);
}

int countChild
int countKChildren(Node* r, int k) {
    
}

int main() {
    int u, v;
    while (1) {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "*") == 0) break;
        else if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);                    
            root = makeNode(u,NULL);
        } 
        else if (strcmp(cmd, "Insert") == 0) {
            scanf("%d %d", &u, &v);             
            Insert(u, v);
        } 
        else if (strcmp(cmd, "CountKChildren") == 0) {
            int u, k;
            scanf("%d %d", &u, &k);
            Node* r = find(root, u);
            printf("%d\n", countKChildren(r, k));
        } 
    }
}
