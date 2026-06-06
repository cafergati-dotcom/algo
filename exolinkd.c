#include<stdio.h>
#include <stdlib.h>
typedef struct node {
int data;
struct node *next;
}node;
int main (){
struct node head=NULL;
struct node second=NULL;
struct node third=NULL;
head=malloc(sizeof(node));
second=malloc(sizeof(node));
third=malloc(sizeof(node));
head->data=10;
head->next=second;

second->data=20;
second->next=third;

third->data=30;
third->next=NULL.
struct node*temp=head;
while(temp!=NULL){
    printf("%d ->", temp->data);
    temp=temp-next;
}
printf("NULL"\n);    
return 0;
}