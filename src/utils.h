#ifndef MROC_UTILS_HEADER
#define MROC_UTILS_HEADER

#include <stdio.h>
#include <stdlib.h>

#ifndef CHECKEQ
#define CHECKEQ(x, y) {if(!(x==y)) { \
            printf("CHECKEQ FAILED: %s at line:%d", __FILE__, __LINE__);\
            exit(EXIT_FAILURE) }}
#endif

#ifndef max
#define max(x, y) (x>y)?x:y
#endif
#ifndef min
#define min(x, y) (x<y)?x:y
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
extern "C" {
#endif
void getInterpolationOnImage(unsigned char* p_mat, const int col, const int row, \
         mroc_point* p_start_pt, mroc_point* p_end_pt, const unsigned char target_value);

#ifdef __cplusplus
}   // extern "C"
#endif

#endif // MROC_UTILS_HEADER
