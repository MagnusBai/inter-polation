#ifndef MROC_UTILS_HEADER
#define MROC_UTILS_HEADER

#include <stdio.h>
#include <stdlib.h>

#ifndef CHECKEQ
#define CHECKEQ(x, y) {if(!(x==y)) { \
            printf("CHECKEQ FAILED: %s at line:%d", __FILE__, __LINE__); \
            exit(EXIT_FAILURE); }}
#endif
#ifndef CHECKNE
#define CHECKNE(x, y) {if(!(x!=y)) { \
            printf("CHECKNE FAILED: %s at line:%d", __FILE__, __LINE__); \
            exit(EXIT_FAILURE); }}
#endif
#ifndef CHECKGT
#define CHECKGT(x, y) {if(!(x>y)) { \
            printf("CHECKGT FAILED: %s at line:%d", __FILE__, __LINE__); \
            exit(EXIT_FAILURE); }}
#endif
#ifndef CHECKGE
#define CHECKGE(x, y) {if(!(x>=y)) { \
            printf("CHECKGE FAILED: %s at line:%d", __FILE__, __LINE__); \
            exit(EXIT_FAILURE); }}
#endif
#ifndef CHECKLT
#define CHECKLT(x, y) {if(!(x<y)) { \
            printf("CHECKLT FAILED: %s at line:%d", __FILE__, __LINE__); \
            exit(EXIT_FAILURE); }}
#endif
#ifndef CHECKLE
#define CHECKLE(x, y) {if(!(x<=y)) { \
            printf("CHECKLE FAILED: %s at line:%d", __FILE__, __LINE__); \
            exit(EXIT_FAILURE); }}
#endif

// There's a std::min and std::max in C++, but AFAIK, there's no equivalent in the C standard library.
// https://stackoverflow.com/questions/3437404/min-and-max-in-c
#ifndef max
#define max(x, y) (x>y)?x:y
#endif
#ifndef min
#define min(x, y) (x<y)?x:y
#endif

#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif


#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  unsigned short x;
  unsigned short y;
} mroc_point;

typedef struct {
  mroc_point start_pt;
  mroc_point end_pt;
} mroc_segment;


#ifdef __cplusplus
}   // extern "C"
#endif

#endif // MROC_UTILS_HEADER
