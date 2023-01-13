#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    struct NODE *left;
    struct NODE *right;
    int data;
} *node;

typedef struct
{
    node head;
} list;

node getnode(int data)
{
    node n = (struct NODE *)malloc(sizeof(struct NODE));
    n->data = data;
    return n;
}

void init(list *l)
{
    l->head=NULL;
}

void insert_front(list *l, int key)
{
    node n = getnode(key);
    if (l->head == NULL)
    {
        l->head = n;
        n->left = NULL;
        n->right = NULL;
        return;
    }
    n->right = l->head;
    n->left = NULL;
    n->right->left = n;
    l->head = n;
}

void delete(list *l,int data)
{
    node cur=l->head;
    if(l->head==NULL){
        return;
    }
    if(cur->data==data && cur->right==NULL){
        free(cur);
        l->head=NULL;
        return;
    }
    if(cur->data==data)
    {
        l->head=cur->right;
        l->head->left=NULL;
        free(cur);
        return;
    }
    cur= cur->right;
    while(cur!=NULL && cur->data!=data)
    {
        cur=cur->right;
    }
    if(cur==NULL){
        return;
    }
    if(cur->right==NULL){
        cur->left->right=NULL;
        free(cur);
        return;
    }
    cur->left->right=cur->right;
    cur->right->left=cur->left;
    free(cur);
}

void display(list *l)
{
    node cur = l->head;
    if (cur == NULL){
        printf("No Bicthes");
        return;
    }
    while (cur!= NULL)
    {
        printf("%d->", cur->data);
        cur = cur->right;
    }
    printf("\n");
}

int main()
{
    list l;
    init(&l);
    insert_front(&l, 10);
    insert_front(&l, 20);
    insert_front(&l, 30);
    // insert_front(&l, 40);
    // insert_front(&l, 50);
    // insert_front(&l, 60);
    display(&l);
    delete(&l,50);
    display(&l);
}