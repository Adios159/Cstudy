#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 20

typedef struct {
    int customer_id;
    int customer_time;
} element;

typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} DequeType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_deque(DequeType *q) {
    q->front = q->rear = 0;
}

int is_empty(DequeType *q) {
    return (q->front == q->rear);
}

int is_full(DequeType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void add_front(DequeType *q, element item) {
    if(is_full(q)) {
        error("deque overflow");
    }
    q->data[q->front] = item;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_front(DequeType *q) {
    if(is_empty(q))
        error("deque uunderflow");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element get_front(DequeType *q) {
    if(is_empty(q))
        error("deque underflow");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_rear(DequeType *q, element item) {
    if(is_full(q)) {
        error("deque overflow");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element delete_rear(DequeType *q) {
    int prev = q->rear;
    if(is_empty(q))
        error("deque uunderflow");
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return q->data[prev];
}

element get_rear(DequeType *q) {
    if(is_empty(q))
        error("deque underflow");
    return q->data[q->rear];
}



void deque_print(DequeType *q) {
    printf("\n");
    printf("\n==== call center queue (total: %d) ====\n", (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE);
    printf("%-10s | %-10s\n", "customer ID", "service time");
    printf("-----------------------------\n");
    if(!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%-10d | %-10d\n", q->data[i].customer_id, q->data[i].customer_time);
            if(i == q->rear)
                break;
        } while(i != q->front);
    }
    printf("-----------------------------\n");
}

int main() {
    DequeType d_instance;
    DequeType *d = &d_instance;
    init_deque(d);
    element customer;
    int servise_time = 60, vip = 5, vip_cnt = 0, current_time = 0, customer_servise_time = 0;
    char cmd = ' ';
    srand(time(NULL));

    printf("Call center simulater.\n");
    while(1) {
        printf("a to add customer, p to print queue: ");
        scanf("%s", &cmd);
        switch(cmd) {
            case 'a':
                customer.customer_id = rand() % 200;
                customer.customer_time = (rand() % 3) + 1;
                if(customer.customer_id % 11 == 0) {
                    if(vip_cnt == vip) {
                        printf("TOO MUCH VIP!!");
                        break;
                    }
                    add_front(d, customer);
                    vip_cnt++;
                }
                else {
                    add_rear(d, customer);
                }
                printf("customer added\n");
                break;
            case 'p':
                deque_print(d);
                break;
            case 'q':
                printf("simulation off\n");
                return 0;
            default:
                printf("wrong command");
                break;
        }
        current_time++;
        customer_servise_time++;
        if(!is_empty(d) && get_front(d).customer_time == customer_servise_time) {
            printf("customer %d service is end\n", get_front(d).customer_id);
            if(customer.customer_id % 11 == 0)
                vip_cnt--;
            delete_front(d);
            customer_servise_time = 0;
        }
    }
}