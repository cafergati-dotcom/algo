#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
   struct node* next;
}node;

typedef struct stack{
   struct node* top;
}stack;

void inistack (stack* s){
s->top = NULL;
};

 int isempty(stack* s)
{return s->top==NULL;}

void prints(stack* s){
node* current = s->top;

printf("top->");
while(current){
    printf("%d->" , current->data);
    current=current->next;
}
}


int pop (stack* s){
if(isempty(s))
{printf("stack empty");}
node* temp = s->top;
int val = temp->data;
s->top = s->top->next;
free(temp);
return val;
}


void push (stack* s, int val){
node* newnode =malloc(sizeof(node));
newnode->data = val;
newnode->next = s->top;
s->top = newnode;
}


int peak(stack* s){
if(isempty(s))
printf("stack empty");

return s->top->data;

}

int main (){
struct stack s;
inistack(&s);
push(&s,10);
push(&s,20);
push(&s,30);
push(&s,40);
push(&s,50);
prints(&s);
return 0;
}
