#include <stdio.h>
#include <stdlib.h> 

typedef struct {
    int max;
    int min;
    float avg;
} p;

p* cs(int arr[], int n) {
    
    p *res =malloc(sizeof(p));
    
    if (res == NULL) exit(-1);

    res->max = arr[0];
    res->min = arr[0];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > res->max) res->max = arr[i];
        if (arr[i] < res->min) res->min = arr[i];
        sum += arr[i];
    }

    res->avg = (float)sum / n;

    return res; 
}

int main() {
    int T[100],n,i;
    printf("enter the size of the array :");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("enter the element %d :",i+1);
        scanf("%d",&T[i]);
    }

    p *data = cs(T, n);

    printf("Max: %d\nMin: %d\nAverage: %.2f\n", data->max, data->min, data->avg);

    free(data);

    return 0;
}
