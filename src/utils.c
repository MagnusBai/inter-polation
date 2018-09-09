#include <math.h>

#include "utils.h"

#ifdef __cplusplus
extern "C" {
#endif

void getInterpolationOnImage(unsigned char* p_mat, const int col, const int row, \
         mroc_point* p_start_pt, mroc_point* p_end_pt, const unsigned char target_value) {
  printf("fuck bitch \n");
  float delta_x = p_end_pt->x - p_start_pt->x;
  float delta_y = p_end_pt->y - p_start_pt->y;

  int n_steps = max(delta_x, delta_y)+1;
  int x_on_trip=0, y_on_trip=0;
  for(int i=0; i<n_steps; ++i) {
    x_on_trip = roundf(delta_x*i/(n_steps-1) + p_start_pt->x);
    y_on_trip = roundf(delta_y*i/(n_steps-1) + p_start_pt->y);
    printf("%d: (%d, %d)\n", i, x_on_trip, y_on_trip);
  }
}

#ifdef __cplusplus
}   // extern "C"
#endif
