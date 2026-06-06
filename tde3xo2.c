#include <stdio.h>
#include <stdlib.h>
int main (){
int n,i, max,min;
int *p;
printf("enter the number n of elments\n");
scanf("%d", &n);
p=malloc(n*sizeof(int));
if (p==NULL){
    return 1;
}
for(i=0;i<n;i++){
    printf("enter p[%d]\n", i);
    scanf("%d", &p[i]);
}
max=p[0];
min=p[0];
for(i=0;i<n;i++){
if(p[i]<min)
        min=p[i];
}
for(i=0;i<n;i++){
if(max<p[i])
    max=p[i];
}
printf("the maximum value in this array is %d\n", max);
printf("the minimum value in this array is %d\n", min);
    
free(p);
return 0;
}