#define MAX_SIZE 100

typedef struct {
    int key;
    char name[30];
} Element;

typedef struct {
    Element heap[MAX_SIZE];
    int heap_size;
} MaxHeap;

// 1) 최대 힙: 업힙 (삽입 시 아래에서 위로 비교/교환)
void up_heap_max(MaxHeap* h, int index) {
    Element temp = h->heap[index];

    // 루트(인덱스 1)에 도달하거나, 부모의 키가 더 크거나 같을 때까지 반복
    while (index > 1 && temp.key > h->heap[index / 2].key) {
        h->heap[index] = h->heap[index / 2]; // 부모를 아래로 내림
        index /= 2;                         // 한 레벨 상승
    }
    h->heap[index] = temp;
}

// 2) 최대 힙: 다운힙 (삭제 시 위에서 아래로 비교/교환)
void down_heap_max(MaxHeap* h, int index) {
    Element temp = h->heap[index];
    int parent = index;
    int child = parent * 2; // 왼쪽 자식

    while (child <= h->heap_size) {
        // 오른쪽 자식이 존재하고, 오른쪽 자식의 키가 더 크면 오른쪽 선택
        if (child < h->heap_size && h->heap[child].key < h->heap[child + 1].key) {
            child++;
        }

        // 현재 원소가 더 큰 자식보다 크거나 같으면 위치 확정
        if (temp.key >= h->heap[child].key) {
            break;
        }

        h->heap[parent] = h->heap[child]; // 자식을 위로 올림
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
}

// 업힙을 활용한 삽입
void insert_max(MaxHeap* h, Element item) {
    h->heap[++(h->heap_size)] = item; // 힙 끝에 원소 추가
    up_heap_max(h, h->heap_size);     // 끝 위치부터 업힙 수행
}

// 다운힙을 활용한 삭제 (최댓값 추출)
Element delete_max(MaxHeap* h) {
    Element max_item = h->heap[1];          // 루트(최댓값)
    h->heap[1] = h->heap[(h->heap_size)--]; // 마지막 원소를 루트로 이동
    down_heap_max(h, 1);                    // 루트부터 다운힙 수행
    return max_item;
}