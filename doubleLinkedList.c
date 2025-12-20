#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node*next;
    struct node*prev;
    int data;
};
struct node *head=NULL;

struct node *createNode(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data =value;
    newnode->next= NULL;
    newnode->prev= NULL;
    return newnode;
}
void insertBeg(int value){
    struct node* newnode= createNode(value);
     if (head == NULL) {
        head = newnode;
    } else {
    newnode->next=head;
    head->prev= newnode;
    newnode=head;
    }
    printf("%d",value);
}
void insertEnd(int value){
    struct node* newnode= createNode(value);
     if (head == NULL) {
        head = newnode;
    } else {
        struct node*tail;
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
void deleteBeg(){
     if (head == NULL) {
        printf("empty list");
    } else{
        struct node*temp=head;
        while(temp!=NULL){
            head->next=head;
            head->prev=NULL;
            free (temp);
        }
    }
}
void deleteEnd(){
     if (head == NULL) {
        printf("empty list");
    } else{
        struct node*tail;
        struct node*temp;
        temp=tail;
        tail->prev=tail;
        tail->next=NULL;
        free(temp);
    }
}
void display(){
    if (head == NULL) {
        printf("empty list");
    } else{
        struct node*temp=head;
        printf("doubly linked list");
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
        

    }


}

