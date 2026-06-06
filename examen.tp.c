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

int max(stack* s){
int max=s->top->data;
node* current=s->top;
while(current!=NULL){
if(max< current->data)
max=current->data;
current=current->next;
}
return max;
}

int min(stack* s){
int min=s->top->data;
node* current=s->top;
while(current!=NULL){
if(min> current->data)
min=current->data;
current=current->next;
}
return min;
}

int main (){
struct stack s;
int n,i,val,result1,result2;
printf("enter the number of elements \n");
scanf("%d", &n);
for(i=0;i<n;i++){
printf("enter the values\n");
    scanf("%d", &val);
    push(&s,val);
}
prints(&s);
result1=max(&s);
result2=min(&s);
printf("the max of your stack is %d :", result1);
printf("the min of your stack %d: ", result2);

    return 0;
}