#include <stdio.h>
int prime(int n){
for(int i=2;i<n-1;i++)
if (n%i==0)
return 0;
else return 1;
}
int main (){
int a,result;
printf("enter the number\n");
scanf("%d", &a);
result =prime(a);
printf("the resultis %d", result);
return 0;
}