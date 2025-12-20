#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node*next;
    int data;
};
struct node *tail = 0;

struct node* createNode(int value){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->next= value;
    newnode->next = NULL;
    return newnode;
}
void insertBeg(int value){
    struct node *newnode=creatNode(value);
    if (tail==NULL){
        tail=newnode;
        tail=tail->next;
    }else{
        struct node*head;
        newnode->next=head;
        tail->next=newnode;
    }
}
void insertEnd(int value){
    struct node *newnode=creatNode(value);
    if(tail==0){
        tail=newnode;
        tail->next=tail;
    }else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}
void deleteBeg(){
    if(tail==0){
        printf("list is empty");
        return;
    }
    struct node*head=tail->next;
    if(tail==head){
        printf("delete element",head->data);
        free(head);
        return;
    }else{
        tail->next=head->next;
        free(head);
    }
    
}
void deleteEnd(){
     if(tail==0){
        printf("list is empty");
        return;
     } struct node *temp=tail->next;
     if(tail==temp){
        printf("deleted data",tail->data);
        free(tail);
        return;
    }else{
        while(temp->next!=0){
            temp=temp->next;
            temp->next=tail->next;
            free(tail);
            tail=temp;
        }
    }
}
void display(){
    if(tail==0){
        printf("list is empty");
        return;
    }
    struct node*temp=tail->next;
    printf("circular list");
    do{
        printf("%d", temp->data);
        temp-temp->next;
    } while(temp!=tail->next);
        printf("back to head");
    
}
