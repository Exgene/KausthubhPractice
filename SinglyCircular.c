#include<stdlib.h>
#include<stdio.h>

typedef struct NODE{
    struct NODE *next;
    int data;
}*node;

typedef struct{
    node head;
    node tail;
}list;

node getnode(int key){
    node n=(struct NODE *)malloc(sizeof(struct NODE));
    n->data=key;
    return n;
}

void init(list *l){
    l->head=NULL;
}

void insert_front(list *l,int key){
    node n;
    if(l->head==NULL){
        n=getnode(key);
        l->head=n;
        n->next=n;
    }
    node cur=l->head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=n;
    n->next=l->head;
    l->head=n;
}

void display(list *l){
    node n=l->head;
    printf("%d",n->data);
    n=n->next;
    while(n->next!=n){
        printf("%d",n->data);
    }
}

int main(){
    list l;
    l.head=NULL;
    l.tail=NULL;
    insert_front(&l,10);
    insert_front(&l,20);
    insert_front(&l,30);
    display(&l);
    return 0;
}