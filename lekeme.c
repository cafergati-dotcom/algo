#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node* next;
}node;

node* create (int val){
node* newnode=malloc(sizeof(node));
newnode->data=val;
newnode->next=NULL;
return newnode;
}

node* ajoutaudeb(node* head, int val){
node* newnode=malloc(sizeof(node));
newnode->data=val;
newnode->next=NULL;
if(head!=NULL)
newnode->next=head;
head=newnode;
return head;
}


node* reverse(node* head){
node* curr=head;
node* prev=NULL;
node*next=NULL;
while (curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
}
 return prev;
}

void kieme(node* head, int k){
head=reverse(head);
node* current=head;
for(int i=1;i<k-1;i++){
    current=current->next;
}
printf("le %d-ieme element depuis la fin est: [%d]", k,current->next->data);
}


void affichage(node* head){
node* current =head;
while(current!=NULL){
    printf("[%d]->", current->data);
    current=current->next;
}
printf("NULL\n");
}

int main (){
node* head=NULL;
head=ajoutaudeb(head,40);
head=ajoutaudeb(head,30);
head=ajoutaudeb(head,20);
head=ajoutaudeb(head,10);
affichage(head);
kieme(head,3);
    return 0;
}