#ifndef GUARD_NUMBERS_H
#define GUARD_NUMBERS_H

#define TEN 10
#define HUNDRED 100
#define THOUSAND 1000
#define MILLION (THOUSAND * THOUSAND)

#define LEAD_DIGIT_100M(v) (v / (HUNDRED * MILLION))
#define LEAD_DIGIT_10M(v) (v / (TEN * MILLION))
#define LEAD_DIGIT_1M(v) (v / (MILLION))
#define LEAD_DIGIT_100S(v) (v / HUNDRED)
#define LEAD_DIGIT_10S(v) (v / TEN)

#define DIGIT_100M(v) ((v % (THOUSAND * MILLION)) / (HUNDRED * MILLION))
#define DIGIT_10M(v) ((v % (HUNDRED * MILLION)) / (TEN * MILLION))
#define DIGIT_1M(v) ((v % (TEN * MILLION)) / MILLION)
#define DIGIT_100K(v) ((v % (MILLION)) / (HUNDRED * THOUSAND))
#define DIGIT_10K(v) ((v % (HUNDRED * THOUSAND)) / (TEN * THOUSAND))
#define DIGIT_1K(v) ((v % (TEN * THOUSAND)) / THOUSAND)
#define DIGIT_100S(v) ((v % THOUSAND) / HUNDRED)
#define DIGIT_10S(v) ((v % HUNDRED) / TEN)
#define DIGIT_1S(v) (v % TEN)

#define DIGIT_1M_SCALEDOWN(v) ((v %= (TEN * MILLION)) / MILLION)
#define DIGIT_100K_SCALEDOWN(v) ((v %= (MILLION)) / (HUNDRED * THOUSAND))
#define DIGIT_10K_SCALEDOWN(v) ((v %= (HUNDRED * THOUSAND)) / (TEN * THOUSAND))
#define DIGIT_1K_SCALEDOWN(v) ((v %= (TEN * THOUSAND)) / THOUSAND)
#define DIGIT_100S_SCALEDOWN(v) ((v %= THOUSAND) / HUNDRED)
#define DIGIT_10S_SCALEDOWN(v) ((v %= HUNDRED) / TEN)

#define TICKS_PER_SEC 60
//m=Minutes, s=Seconds, 60 frames per sec
#define TICKS_FOR_TIME(m,s) ((m * 60 + s) * TICKS_PER_SEC)



#endif // GUARD_NUMBERS_H