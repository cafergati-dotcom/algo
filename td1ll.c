#include<stdio.h>
#include <stdlib.h>

typedef struct node {
int data;
struct node* next;
}node;

node* create(int value){
node* newnode=malloc(sizeof(node));
newnode->data=value;
newnode->next=NULL;
return newnode;
}
int affichage(node *head){
    node* current=head;
    int s=0;
    while(current!=NULL){
        printf("[%d]->",current->data);
        if(current->data <)
         current=current->next;
        }
        printf("NULL\n");
        return s;
}
int main(){
    int n,s;
node* head=NULL;
node* h1=create(1);
node* h2=create(2);
node* h3=create(3);
node* h4=create(4);
head=h1;
h1->next=h2;
h2->next=h3;
h3->next=h4;
h4->next=NULL;
printf("la list est :\n");
s=affichage(head);
printf("\n");
printf("la somme est : %d\n", s);
    return 0;
}