#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} node;
node* add_deb(node* head, int newval) {
    node* newnode = malloc(sizeof(node));
    newnode->data = newval;
    newnode->next = head;
    return newnode;
}
void print(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("[%d]->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int comp(node* head1, node* head2) {
    node* c1 = head1;
    node* c2 = head2;

    while (c1 != NULL && c2 != NULL) {
        if (c1->data != c2->data) {
            printf("Result: They are NOT the same (Different values)\n");
            return 0;
        }
        c1 = c1->next;
        c2 = c2->next;
    }

    if (c1 == NULL && c2 == NULL)
        printf("Result: They are the SAME\n");
    else
        printf("Result: They are NOT the same (Different lengths)\n");
        return 1;
}

node* reverse(node* head1){
node* current =head1;
node* next=NULL;
node* prev= NULL;
while(current!=NULL){
next=current->next;
current->next=prev;
prev=current;
current=next;
}
return prev;
}

int main() {
   int result;
    node* head1 = NULL;
    node* head2 = NULL;
    head1 = add_deb(head1, 1);
    head1 = add_deb(head1, 2);
    head1 = add_deb(head1, 2);
    head1 = add_deb(head1, 3);
    head1 = add_deb(head1, 1);

    printf("List 1: "); print(head1);
    head2=reverse(head1);
    printf("List 2: "); print(head2);

   result= comp(head1, head2);
if(result==0){
    printf("they are not palyndrom");
}
if (result==1){
    printf("they are palyndrom");
}
    return 0;
}