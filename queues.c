#include <stdio.h>
#define MAX 5

int queue[MAX], front=-1, rear=-1;

void enqueue(int value) {
    if(rear==MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if(front==-1) front=0;
        queue[++rear]=value;
        printf("Inserted %d\n", value);
    }
}

void dequeue() {
    if(front==-1 || front>rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted %d\n", queue[front++]);
        if(front > rear) front=rear=-1;//reset pointers
    }
}

void display() {
    if(front==-1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for(int i=front; i<=rear;i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    display();
    return 0;
}