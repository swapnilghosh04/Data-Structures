#include <iostream> //17. reverse stack using additional queue
#include <stdlib.h>
#define MAX_SIZE 100
struct Queue {
int items[MAX_SIZE];
int front;
int rear;
};
struct Stack {
int items[MAX_SIZE];
int top;
};
void enqueue(struct Queue *q, int item) {
if (q->rear == MAX_SIZE - 1) {
std::cout << "Queue overflow\n";
return;
}
if (q->front == -1)
q->front = 0;
q->rear++;
q->items[q->rear] = item;
}
int dequeue(struct Queue *q) {
if (q->front == -1) {
std::cout << "Queue underflow\n";
return -1;
}
int item = q->items[q->front];
q->front++;
if (q->front > q->rear)
q->front = q->rear = -1;
return item;
}
void display(struct Queue *q) {
if (q->rear == -1) {
std::cout << "Queue is empty\n";
return;
}
for (int i = q->front; i <= q->rear; i++)
std::cout << q->items[i] << " ";
std::cout << std::endl;
}
void push(struct Stack *s, int item) {
if (s->top == MAX_SIZE - 1) {
std::cout << "Stack overflow\n";
return;
}
s->top++;
s->items[s->top] = item;
}
int pop(struct Stack *s) {
if (s->top == -1) {
std::cout << "Stack underflow\n";
return -1;
}
int item = s->items[s->top];
s->top--;
return item;
}
int main() {

    struct Queue q;
    q.front = -1;
    q.rear = -1;
    
    struct Stack s;
    s.top = -1;

    int n, item;

    std::cout << "Enter the number of elements to be inserted in the queue: ";

    std::cin >> n;

    std::cout << "Enter the elements:\n";

    for (int i = 0; i < n; i++) {

        std::cin >> item;

        enqueue(&q, item);

    }

    std::cout << "Queue before reversing:\n";

    display(&q);

    while (q.front != -1)

        push(&s, dequeue(&q));

    while (s.top != -1)

        enqueue(&q, pop(&s));

    std::cout << "Queue after reversing:\n";

    display(&q);

    return 0;

}

