#include<stdio.h>
#include <stdlib.h>
typedef struct node{
int data;
struct node* next;
} node;

node* create(int value){
node* newnode=malloc(sizeof(node));
newnode->data=value;
newnode->next=NULL;
return newnode;
}


void affichage(node* head){
node* current =head;
while(current!=NULL){
    printf("[%d]->", current->data);
    current=current->next;
}
printf("NULL\n");
}


int taille(node* head){
    node* current =head;
    int count =0;
    while(current !=NULL){
    current=current->next;
    count=count+1;
    }
    return count;
}


int recher(node* head, int val){
node* current =head;
 while(current !=NULL){
if(current->data==val)
return val;
current=current->next;
 }
 return -1;
}


node* ajoudebut(node* head, int newv){
node* newnode=malloc(sizeof(node));
newnode->data=newv;
newnode->next=NULL;

if(head!=NULL)
newnode->next=head;
head=newnode;
return head;
}

node* ajoutfin(node* head, int val){
    node* current=head;
node* newnode=malloc(sizeof(node));
newnode->data=val;
newnode->next=NULL;
if(head==NULL)
return newnode;
while(current->next!=NULL){
    current=current->next;
}
  current->next=newnode;
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

node* deletedeb(node* head){
node* current=head;
if(head==NULL)return NULL;

head=head->next;
free(current);
return head;
}
node* merge(node* head1, node* head2){
if(head1==NULL) return head2;
if(head2==NULL) return head1;
node* current=head1;
while(current!=NULL){
    current=current->next;

}
current->next=head2;
return head2;
}

int main(){
    int n;
    node* result;
node* head=NULL;
node* h1=create(10);
node* h2=create(20);
node* h3=create(30);
head=h1;
h1->next=h2;
h2->next=h3;
h3->next=NULL;

node* head2=NULL;
node* hd1=create(50);
node* hd2=create(60);
node* hd3=create(70);
head2=hd1;
hd1->next=hd2;
hd2->next=hd3;
hd3->next=NULL;

affichage(head);
n=taille(head);
printf("-------------------------------------------\n");
printf("la taille de ta liste est %d\n", n);

printf("-------------------------------------------\n");
printf("your new list is \n");
head=ajoudebut(head,1);
head=ajoudebut(head,0);
affichage(head);
printf("-------------------------------------------\n");
taille(head);
printf("la taille apres l'ajout est %d :\n", taille(head));
head=ajoutfin(head,40);
printf("-------------------------------------------\n");
printf("la  liste apres l'ajout est %d :\n");
affichage(head);
printf("-------------------------------------------\n");
taille(head);
printf("la taille apres l'ajout est %d :\n", taille(head));
printf("-------------------------------------------\n");
head=reverse(head);
printf("la liste inversée est :\n");
affichage(head);
printf("-------------------------------------------\n");
printf("la liste aprés la supression du 1er element :\n");
head=deletedeb(head);
affichage(head);
printf("-------------------------------------------\n");
taille(head);
printf("la taille apres la supression est %d :\n", taille(head));
printf("-------------------------------------------\n");
taille(head2);
printf("la taille de ta liste est %d\n", n);
printf("-------------------------------------------\n");
result=merge(head,head2);
printf("la liste apres mergine est;\n");
affichage(result);
    return 0;
}