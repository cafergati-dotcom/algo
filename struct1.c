#include <stdio.h>

struct students {
    char name[50];
    int age;
    float tm;
};

int main() {
    struct students s[3];
    float sum = 0;
    int i;

    for (i = 0; i <3; i++) {
        printf("enter name, age and tm of the student number %d\n", i + 1);
        scanf(" %[^\n] %d %f", s[i].name, &s[i].age, &s[i].tm);
        sum = sum + s[i].tm;
    }

    for (i = 0; i < 3; i++) {
        printf("student %d: %s, age:%d, tm:%.2f\n",
               i + 1, s[i].name, s[i].age, s[i].tm);
    }

    printf("the average is %.2f\n", sum / 2);

    return 0;
}
 