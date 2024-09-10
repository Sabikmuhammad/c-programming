#include <stdio.h>
#include<string.h>
struct Person {
    char name[50];
    int age;
    float height;
};

int main() {
    struct Person people[3];

   
    strcpy(people[0].name, "sabik");
    people[0].age = 19;
    people[0].height = 5.5;
    strcpy(people[1].name, "rohith");
    people[1].age = 19;
    people[1].height = 6.0;
    strcpy(people[2].name, "karthik");
    people[2].age = 19;
    people[2].height = 5.8;
    for(int i = 0; i < 3; i++) {
        printf("Name: %s, Age: %d, Height: %.1f\n", people[i].name, people[i].age, people[i].height);
    }

    return 0;
}