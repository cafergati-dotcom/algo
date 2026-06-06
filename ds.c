#include <stdio.h>
#include <stdlib.h>



typedef struct node{
    int data;
    struct node* next;
}node;




node* ajout(node* head,int val){
node* newnode=malloc(sizeof(node));
newnode->data=val;
newnode->next=head;
return newnode;
}



void print(node* head){
node* current=head;
while(current!=NULL){
    printf("[%d]->",current->data);
    current=current->next;
}
printf("NULL");
}




node* ajoum(node*head,int pos,int val){
node* newnode=malloc(sizeof(node));
newnode->data=val;
newnode->next=NULL;
node* current=head;
while(current!=NULL){
for(int i=0;i<pos;i++){
    current=current->next;
}
current->next=newnode;
newnode->next=current->next->next;
}
return head;
}



 void comp(node* head1, node* head2) {
    node* c1 = head1;
    node* c2 = head2;

    while (c1 != NULL && c2 != NULL) {
        if (c1->data != c2->data) {
            printf("Result: They are NOT the same (Different values)\n");
        }
        c1 = c1->next;
        c2 = c2->next;
    }

    if (c1 == NULL && c2 == NULL)
        printf("Result: They are the SAME\n");
    else
        printf("Result: They are NOT the same (Different lengths)\n");
}


int sup (node* head,int pos){
    node* temp=NULL;
    node* current=head;
    
while(current!=NULL){
for(int i=0;i<pos;i++){
    current=current->next;
}
temp=current->next;
int val=temp->data;
current->next=temp->next;
free(temp);
return val;
}
}


node* merging (node* h1, node* h2){
node* current=h1;
if(h1==NULL) return h2;
if(h2==NULL) return h1;
while(current!=NULL){
current=current->next;
}
current->next=h2;
return h1;
}


node* create(node* head,int n){
head=NULL;
int val;
for(int i=0;i<n;i++){
    printf("enter the values;\n");
scanf("%d", &val);
head=ajout(head,val);
}
return head;
}


int main (){
node* head=NULL;
node* hea2=NULL;
int n1; 
int n2;
printf("enter the number of elements of list1:\n");
scanf("%d",&n1);
head=create(head,n1);
print(head);
printf("\n enter the number of elements of list2:\n");
scanf("%d",&n2);
hea2=create(head,n2);
print(hea2);
printf("\n");
comp(head,hea2);
    return 0;
}