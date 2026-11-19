#include <stdio.h>
#define MAX_VERTICES 100

int parent[MAX_VERTICES];

void set_init(int n) {
    for(int i = 0; i < n; i++) {
        parent[i] = -1;
    }
}

int set_find(int curr) {
    if(parent[curr] == -1) {
        return curr;
    }
    while(parent[curr] != -1)
        curr = parent[curr];
    return curr;
}

void set_union(int a, int b) {
    int root1 = set_find(a);
    int root2 = set_find(b);
    if(root1 != root2)
        parent[root1] = root2;
}

static int pass_cnt = 0, fail_cnt = 0;

static void check(const char *name, int cond) {
    if(cond) {
        pass_cnt++;
        printf("[PASS] %s\n", name);
    } else {
        fail_cnt++;
        printf("[FAIL] %s\n", name);
    }
}

static int same(int a, int b) {
    return set_find(a) == set_find(b);
}

static void print_sets(int n) {
    printf("  원소 : ");
    for(int i = 0; i < n; i++) printf("%2d ", i);
    printf("\n  대표 : ");
    for(int i = 0; i < n; i++) printf("%2d ", set_find(i));
    printf("\n");
}

int main(void) {
    int n = 10;

    printf("=== 1. 초기화 ===\n");
    set_init(n);
    int all_alone = 1;
    for(int i = 0; i < n; i++)
        if(set_find(i) != i) all_alone = 0;
    check("초기에는 모든 원소가 자기 자신이 대표", all_alone);
    check("초기에는 서로 다른 집합 (0, 1)", !same(0, 1));
    print_sets(n);

    printf("\n=== 2. 기본 union ===\n");
    set_union(0, 1);
    set_union(2, 3);
    check("union(0,1) 후 같은 집합", same(0, 1));
    check("union(2,3) 후 같은 집합", same(2, 3));
    check("{0,1}과 {2,3}은 아직 다른 집합", !same(1, 2));
    print_sets(n);

    printf("\n=== 3. 집합 병합 ===\n");
    set_union(1, 3);
    check("union(1,3) 후 0과 2도 같은 집합", same(0, 2));
    check("union(1,3) 후 0과 3도 같은 집합", same(0, 3));
    check("{0,1,2,3}과 4는 다른 집합", !same(0, 4));
    print_sets(n);

    printf("\n=== 4. 같은 집합끼리 중복 union ===\n");
    int root_before = set_find(0);
    set_union(0, 3);
    set_union(2, 1);
    check("중복 union 해도 대표 불변", set_find(0) == root_before);
    check("중복 union 해도 여전히 같은 집합", same(1, 2));

    printf("\n=== 5. 체인 형태 (깊은 트리) ===\n");
    set_union(5, 6);
    set_union(6, 7);
    set_union(7, 8);
    set_union(8, 9);
    check("5와 9가 같은 집합", same(5, 9));
    check("5~9와 0~3은 다른 집합", !same(5, 0));
    print_sets(n);

    printf("\n=== 6. 전체 병합 ===\n");
    set_union(4, 0);
    set_union(0, 9);
    int all_same = 1;
    for(int i = 1; i < n; i++)
        if(!same(0, i)) all_same = 0;
    check("모든 원소가 하나의 집합", all_same);
    print_sets(n);

    printf("\n=== 7. 경계값 ===\n");
    set_init(1);
    check("원소 1개: find(0) == 0", set_find(0) == 0);
    set_union(0, 0);
    check("자기 자신과 union 해도 문제 없음", set_find(0) == 0);

    set_init(MAX_VERTICES);
    for(int i = 1; i < MAX_VERTICES; i++)
        set_union(i - 1, i);
    check("MAX_VERTICES개 체인 병합 후 0과 99가 같은 집합", same(0, MAX_VERTICES - 1));

    printf("\n=== 결과: PASS %d / FAIL %d ===\n", pass_cnt, fail_cnt);
    return fail_cnt ? 1 : 0;
}