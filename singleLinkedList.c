#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node*next;
    int data;
};
struct node *head = 0;

struct node* createNode(int value){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->next= value;
    newnode->next = NULL;
    return newnode;
}
void insertBeg(int value){
    struct node *newnode=creatNode(value);
    head= newnode->next;
    head = newnode;
}
void insertEnd(int value){
    struct node *newnode=creatNode(value);
    if (head==NULL){
        head=newnode;
        printf("%d",value);
        return;
    }else {
        struct node *temp=head;
        while(temp->next=NULL){
            temp=temp->next;
            temp->next=newnode;
            printf("%d", value);
        }
    }
}
void deleteBeg(){
    if (head==NULL){
        printf("list is empty");
        return;
    }
    struct node *temp=head;
    head=head->next;
    printf("%d", temp->data);
    free(temp);
}
void deleteEnd(){
    if (head==NULL){
        printf("list is empty");
        return;
    }else{
        struct node *temp=head;
        struct node *prev=NULL;
        while(temp->next!=NULL){
            prev=temp;          
            temp=temp->next;
        }if(temp==head){
            head=NULL;
            free(temp);
        }else{
            prev->next=0;
            free(temp);
        }
    }
}
void display(){
     if (head==NULL){
        printf("list is empty");
        return;
    }else{
        struct node *temp=head;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp =temp->next;
        }
    }

}



