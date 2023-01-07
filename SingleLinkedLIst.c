#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *next;
}*node;

typedef struct{
    node head;
}list;

void getnode(node *n){
    *n=(struct NODE *)malloc(sizeof(struct NODE));
}

void insert_front(list *l,int data){
    node cur;
    getnode(&cur);
    cur->data=data;
    cur->next=l->head;
    l->head=cur;
}

void display(list *l){
    node cur=l->head;
    while(cur!=NULL){
        printf("%d->",cur->data);
        cur=cur->next;
    }
    printf("\n");
}

void delete_rear(list *l){
    node cur=l->head;
    if(cur->next==NULL){
        free(cur);
        l->head=NULL;
        return;
    }
    while(cur->next->next!=NULL){
        cur=cur->next;
    }
    node temp=cur;
    cur->next=NULL;
    free(temp->next);
}

int main(){
    list l;
    l.head=NULL;
    insert_front(&l,10);
    insert_front(&l,20);
    insert_front(&l,30);
    insert_front(&l,40);
    insert_front(&l,50);
    display(&l);
    delete_rear(&l);
    display(&l);
    return 0;
}