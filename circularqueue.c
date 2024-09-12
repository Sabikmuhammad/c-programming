#include <stdio.h>
#define MAX 5

int cqueue[MAX], front=-1, rear=-1;

void enqueue(int value) {
    if((front==0 && rear==MAX-1) || (rear+1)%MAX==front) {
        printf("Circular Queue Overflow\n");
    } else {
        if(front==-1) front=rear=0;
        else rear=(rear+1)%MAX;
        cqueue[rear]=value;
        printf("Inserted %d\n", value);
    }
}

void dequeue() {
    if(front==-1) {
        printf("Circular Queue Underflow\n");
    } else {
        printf("Deleted %d\n", cqueue[front]);
        if(front==rear) front=rear=-1;
        else front=(front+1) % MAX;
    }
}

void display() {
    if(front==-1) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Circular Queue elements are:\n");
        int i=front;
        while(1) {
            printf("%d\n",cqueue[i]);
            if(i==rear) break;
            i=(i+1)%MAX;
        }
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    enqueue(5);
    display();
    return 0;
}