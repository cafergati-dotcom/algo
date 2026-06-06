#include <stdio.h>
#include <stdlib.h>
int main(){
 int n,i;
 double *u;
 printf("enter the number you want to calculate in the sequence:");
 scanf("%d", &n);
 u=(double*)malloc(n*sizeof(double));
 if(u==NULL){
     printf("la mémoire n'est pas alloué.");
    exit(-1);
 }
 else{
     u[0]=1;
     for(i=0;i<n-1;i++){
         u[i+1]=(u[i]*u[i])+u[i];
     }
     printf("le tableau des elements de la suite:\n");
     for(i=0;i<n;i++){
         printf("u[%d] : %.0lf\n",i,u[i]);
     }
     free(u);
 }

return 0;
}