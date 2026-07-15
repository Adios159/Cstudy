#include "random.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>

/*
 * splitmix64 - 시드 확산(seed spreading) 함수
 * 출처: Vigna, S., "splitmix64", 2015.
 *       xorshift/xoshiro 계열 공식 문서에서 시딩용으로 권장하는 방식.
 * 역할: 사용자가 넘긴 시드(예: 1, 2, 3처럼 연속된 값)를 그대로 상태로 쓰면
 *       초기 결과가 서로 비슷해지는 문제가 있음. 이를 방지하기 위해
 *       시드를 한 번 더 잘 섞어(diffuse) 상태 배열을 채운다.
 */
static uint64_t splitmix64(uint64_t *seed) {
    uint64_t z = (*seed += 0x9E3779B97f4A7C15ULL);
    z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
    z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
    return z ^ (z >> 31);
}

/*
 * xorshift128+ 코어 알고리즘
 * 출처: Vigna, S., "Further scramblings of Marsaglia's xorshift generators",
 *       Journal of Computational and Applied Mathematics, 2016.
 * 특징: BigCrush(TestU01 통계 검정 스위트) 통과, glibc rand()보다 빠르고
 *       주기(2^128 - 1)가 길어 경쟁 프로그래밍/시뮬레이션 용도로 충분함.
 */
static uint64_t xorshift128plus(uint64_t *s) {
    uint64_t s1 = s[0];
    const uint64_t s0 = s[1];
    uint64_t result = s0 + s1;
    s[0] = s0;
    s1 ^= s1 << 23;
    s1 ^= s1 >> 17;
    s1 ^= s0;
    s1 ^= s0 >> 26;
    s[1] = s1;
    return result;
}

void rng_seed(rng_t *rng, uint64_t seed) {
    if (seed == 0) {
        seed = (uint64_t)time(NULL) ^ (uint64_t)(uintptr_t)rng;
    }
    uint64_t sm_state = seed;
    rng->state[0] = splitmix64(&sm_state);
    rng->state[1] = splitmix64(&sm_state);

    /* xorshift는 상태가 전부 0이면 그 이후로 계속 0만 반환하며 고착됨.
     * splitmix64 특성상 사실상 발생하지 않지만 방어적으로 처리. */
    if (rng->state[0] == 0 && rng->state[1] == 0) {
        rng->state[0] = 1;
    }
}

uint64_t rng_next(rng_t *rng) {
    return xorshift128plus(rng->state);
}

int rng_int(rng_t *rng, int min, int max) {
    if (min > max) {
        int tmp = min;
        min = max;
        max = tmp;
    }
    uint64_t range = (uint64_t)((int64_t)max - (int64_t)min) + 1;
    if (range == 0) {
        /* min == INT_MIN, max == INT_MAX인 극단적 경우: 오버플로 방지 */
        return (int)rng_next(rng);
    }

    /*
     * Lemire의 구간 정수 생성법 (modulo bias 제거)
     * 출처: Lemire, D., "Fast Random Integer Generation in an Interval",
     *       ACM Transactions on Modeling and Computer Simulation, 2019
     *       (arXiv:1805.10941).
     * 문제: 흔히 쓰는 `rand() % n`은 RAND_MAX가 n의 배수가 아니면
     *       특정 값이 조금 더 자주 나오는 편향이 생김.
     * 해결: threshold 미만인 결과를 재추첨(rejection sampling)해서
     *       균등분포를 보장.
     */
    uint64_t threshold = (uint64_t)(-range) % range;
    uint64_t r;
    do {
        r = rng_next(rng);
    } while (r < threshold);

    return min + (int)(r % range);
}

double rng_double(rng_t *rng) {
    /* double의 유효 정밀도(가수부 53비트)에 맞춰 상위 53비트만 사용 */
    return (double)(rng_next(rng) >> 11) * (1.0 / 9007199254740992.0); /* 2^53 */
}

double rng_double_range(rng_t *rng, double min, double max) {
    return min + rng_double(rng) * (max - min);
}

int rng_bool(rng_t *rng, double probability) {
    return rng_double(rng) < probability;
}

void rng_shuffle(rng_t *rng, void *base, size_t nmemb, size_t size) {
    if (nmemb < 2 || base == NULL) return;

    unsigned char *arr = (unsigned char *)base;
    unsigned char *tmp = malloc(size);
    if (tmp == NULL) return; /* 셔플용 임시버퍼 할당 실패 시 조용히 포기 */

    /* Fisher-Yates 셔플: 뒤에서부터 앞으로 순회하며 무작위 위치와 교환 */
    for (size_t i = nmemb - 1; i > 0; i--) {
        size_t j = (size_t)rng_int(rng, 0, (int)i);
        memcpy(tmp, arr + i * size, size);
        memcpy(arr + i * size, arr + j * size, size);
        memcpy(arr + j * size, tmp, size);
    }

    free(tmp);
}
