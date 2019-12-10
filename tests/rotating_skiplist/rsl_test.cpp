
#include <assert.h>
#include <getopt.h>
#include <limits.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdint.h>

#include <atomic_ops.h>

#include "tm.h"
#include "ptst.h"
#include "garbagecoll.h"

#define DEFAULT_DURATION                10000
#define DEFAULT_INITIAL                 256
#define DEFAULT_NB_THREADS              1
#define DEFAULT_RANGE                   0x7FFFFFFF
#define DEFAULT_SEED                    0
#define DEFAULT_UPDATE                  20
#define DEFAULT_ELASTICITY              4
#define DEFAULT_ALTERNATE               0
#define DEFAULT_EFFECTIVE               1
#define DEFAULT_UNBALANCED              0

#define XSTR(s)                         STR(s)
#define STR(s)                          #s

#define ATOMIC_CAS_MB(a, e, v)          (AO_compare_and_swap_full((volatile AO_t *)(a), (AO_t)(e), (AO_t)(v)))
#define ATOMIC_FETCH_AND_INC_FULL(a)    (AO_fetch_and_add1_full((volatile AO_t *)(a)))

#define TRANSACTIONAL                   d->unit_tx

#define VAL_MIN                         INT_MIN
#define VAL_MAX                         INT_MAX

inline long rand_range(long r); /* declared in test.c */

#include "intset.h"
#include "background.h"
  
using namespace std; 

int main() 
{ 
    // prints hello world 
    set_t *set;
    ptst_subsystem_init();
    gc_subsystem_init();
    set_subsystem_init();
    set = set_new(1);
    // cout << "success" << endl;

    return 0; 
}