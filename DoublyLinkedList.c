#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    struct NODE *left;
    struct NODE *right;
    int data;
}*node;

typedef struct{
    node head;
}list;

node getnode(int data){
    node n=(struct NODE *)malloc(sizeof(struct NODE));
    n->data=data;
    return n;
}

void insert_front(list *l,int key){
    
}