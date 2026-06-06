#include<stdio.h>
#include <stdlib.h>
typedef struct node {
int data;                                                                        
struct node *next;
}node;

node* create(int n){
node* newnode=malloc(sizeof(node));
if(newnode==NULL)return NULL;
newnode->data=n;
newnode->next=NULL;
return newnode;
}
void affichage(node* head){
node* current=head;
while(current!=NULL){
    printf("[%d] ->", current->data);
    current=current->next;
}
printf("NULL\n");
}
int taille(node* head){
node *current=head;
int count=0;
while(current!=NULL){
    current=current->next;
    count=count+1;
}
return count;
}

int main(){
    int n,i,val,result;
    node *head= NULL, *last=NULL,*temp=NULL;
    printf("enter the number of nodes\n");
    scanf("%d", &n);
for(i=0;i<n;i++){
printf("enter the value\n");
scanf("%d", &val);
temp=create(val);
if(head==NULL){
    head=temp;
    last=temp;
}else{
    last->next=temp;
    last=temp;
}
}
affichage(head);
result=taille(head);
printf("la taille est %d\n", result);
return 0;
}