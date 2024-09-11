#include <stdio.h>
#include<string.h>
struct Address {
    char city[50];
    char state[50];
};

struct Person {
    char name[50];
    int age;
    struct Address address;
};

int main() {
    struct Person person1;

    
    strcpy(person1.name, "sabik");
    person1.age = 19;
    strcpy(person1.address.city, "puttur");
    strcpy(person1.address.state, "karnataka");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("City: %s\n", person1.address.city);
    printf("State: %s\n", person1.address.state);

    return 0;
}