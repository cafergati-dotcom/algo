#include <stdio.h>
void remplace (int t[] ,int n){
    int i;
   for(i=0;i<n;i++){
        if(t[i]<0)
        t[i]=0;
    }
}
int main (){
int n, i, t[100];
printf("enter the number of elements\n");
scanf("%d", &n);
for(i=0;i<n;i++){
    printf("enter the element number %d\n", i+1);
    scanf("%d", &t[i]);
}
 printf("your new array is\n");
 remplace(t, n);
for(i=0;i<n;i++){
    printf("%d", t[i]);
}
return 0;
}