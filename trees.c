#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node* left;
struct node* right;
}node;

node* create(int val){
node* newnode=malloc(sizeof(node));
newnode->data=val;
newnode->left=NULL;
newnode->right=NULL;
return newnode;}

node* insert(node* root, int val){
if(root==NULL) return create(val);
if(val<root->data)
root->left=insert(root->left,val);
if(val>root->data)
root->right=insert(root->right,val);}



void inorder(node* root){
if(root==NULL) return;
inorder(root->left);
printf("%d",root->data);
inorder(root->right);}

void preorder(node* root){
    if(root==NULL)return;
    
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder (node* root){
if(root==NULL) return;
postorder(root->left);
postorder(root->right);
printf("%d", root->data);}

node* search(node* root,int val){
    if(root==NULL ||root->data==val)
return root;
if (val>root->data)

return search(root->right,val);
return search(root->left,val);
}
 

int countleft (node* root){
if (root==NULL) return 0;
return 1+ countleft(root->left);}



int hight(node* root){
int lefth=height(root->left);
int righth=height(root->right);
if(lefth>righth){
return lefth+1;}
else return righth+1;
}
int main (){
node* root=NULL;
int value[]={10,20,30,40,50,60};
int n=6,i;
for(i=0;i<6;i++){

}
    return 0;
}