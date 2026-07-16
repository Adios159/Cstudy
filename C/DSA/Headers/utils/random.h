#ifndef RANDOM_H
#define RANDOM_H

#include <stdint.h>
#include <stddef.h>

/*
 * random.h - 경량 의사난수 생성(PRNG) 모듈
 *
 * 알고리즘: xorshift128+
 * - rand()/srand() 대신 사용하는 이유는 random.c 상단 주석 및 채팅 설명 참고
 * - 암호학적으로 안전하지 않음 (예측 가능한 시퀀스). 보안 목적의 난수가
 *   필요하면 이 모듈 대신 OS 제공 CSPRNG(Linux: getrandom(2), /dev/urandom)를 쓸 것.
 */

typedef struct {
    uint64_t state[2];
} rng_t;

/* seed == 0 이면 시간 기반으로 자동 시드 설정 */
void rng_seed(rng_t *rng, uint64_t seed);

/* 0 ~ UINT64_MAX 범위의 원시 64비트 난수 */
uint64_t rng_next(rng_t *rng);

/* [min, max] 범위의 정수 난수 (양 끝 포함, 모듈로 편향 제거) */
int rng_int(rng_t *rng, int min, int max);

/* [0.0, 1.0) 범위의 실수 난수, 53비트 정밀도 */
double rng_double(rng_t *rng);

/* [min, max) 범위의 실수 난수 */
double rng_double_range(rng_t *rng, double min, double max);

/* 확률 probability(0.0~1.0)로 참(1)을 반환 */
int rng_bool(rng_t *rng, double probability);

/* Fisher-Yates 셔플: 임의 타입 배열을 무작위로 섞음 (in-place) */
void rng_shuffle(rng_t *rng, void *base, size_t nmemb, size_t size);

#endif /* RANDOM_H */
