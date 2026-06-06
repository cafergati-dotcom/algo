#include <stdio.h>
int function(int n){
int sum=0,digit;
while (n>0){
digit=n%10;
sum=sum+digit;
n=n/10;
}
return sum;
}
int main (){
int n,result;
printf(" enter the number a \n");
scanf("%d", &n);
result= function (n);
printf("the sum =%d", result);

return 0;
}