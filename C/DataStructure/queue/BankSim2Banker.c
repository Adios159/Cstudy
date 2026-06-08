#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 7

typedef struct {
    int id;
    int arrival_time;
    int service_time;
} element;

typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

int is_full(QueueType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType *q) {
    printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d | ", q->data[i].id);  // 수정: .id 명시
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType *q, element data) {
    if (is_full(q))
        error("queue overflow");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = data;
}

element dequeue(QueueType *q) {
    if (is_empty(q))
        error("queue underflow");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q) {
    if (is_empty(q))
        error("queue underflow");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];  // 수정: * -> +
}

int main(void) {
    int minutes = 60;
    int total_wait = 0;
    int total_customers = 0;
    int service_time = 0;
    int service_customer;
    QueueType queue, queue2;
    init_queue(&queue);
    init_queue(&queue2);

    srand(time(NULL));
    for (int clock = 0; clock < minutes; clock++) {
        printf("current time: %d\n", clock);
        if ((rand() % 10) < 3) {
            element customer;
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = (rand() % 3) + 1;  // 수정: & -> %, 괄호 추가
            if (is_full(&queue)) {
                enqueue(&queue2, customer);  // 수정: else 분기로 분리
            } else {
                enqueue(&queue, customer);
            }
            printf("id %d customer is coming in %d minutes. service time: %d\n",
                customer.id, customer.arrival_time, customer.service_time);
        }
        if (service_time > 0) {
            printf("id %d customer is on service\n", service_customer);
            service_time--;
        } else {
            if (!is_empty(&queue)) {
                element customer = dequeue(&queue);
                service_customer = customer.id;
                service_time = customer.service_time;
                printf("id %d customer has started service. waiting time was %d\n",
                    customer.id, clock - customer.arrival_time);  // 수정: 인자 정리
                total_wait += clock - customer.arrival_time;  // 수정: == -> +=
            }
        }
    }
    printf("total waiting time: %d\n", total_wait);
    return 0;
}