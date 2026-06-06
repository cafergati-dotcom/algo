#include<stdio.h>
#include <stdlib.h>
int main (){
int i,*p,n,max;
printf ("enter the number of elements \n");
scanf("%d", &n);
p=malloc(n*sizeof(int));
if(p==NULL)
return -1;
for(i=0;i<n;i++){
    printf("enter the element p[%d]", i);
    scanf("%d", &p[i]);
}
max=*p;
for(i=0;i<n;i++){
if(*(p+i)>max)
max=*(p+i);
}
printf("the max is %d\n", max);

free(p);
    return 0;
}