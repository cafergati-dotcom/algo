#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
node* next;
}node;
node* top=NULL;
void push(int value){
    node* newnode =malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;
    top=newnode;
}

int pop(){
if(top==NULL){
    return -1;
}
node*current=top;
int popval=current->data;
top=top->next;
free(current);
return popval;
}

int peek (){
if(top!=NULL){
    return pop->data;
}
}

int isempty (){
return top=NULL;

}