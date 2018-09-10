#include "mroc_interpolation.h"

#include <math.h>  // roundf() fabsf()
#include <string.h>  // memcpy()

mroc_point* getLinearInterpolationWith2Points( \
    mroc_point* const IN p_start_pt, \
    mroc_point* const IN p_end_pt, \
    int* OUT p_num_points_array) {
  float delta_x = p_end_pt->x - p_start_pt->x;
  float delta_y = p_end_pt->y - p_start_pt->y;
  int n_steps = max(fabsf(delta_x), fabsf(delta_y))+1;

  // OUTPUT stray-pointer of points-list
  mroc_point* out_point_list = (mroc_point*)malloc(n_steps*sizeof(mroc_point));

  for(int i=0; i<n_steps; ++i) {
    int x_on_trip = roundf(delta_x*i/(n_steps) + p_start_pt->x);
    int y_on_trip = roundf(delta_y*i/(n_steps) + p_start_pt->y);
    out_point_list[i].x = x_on_trip;
    out_point_list[i].y = y_on_trip;
  }

  // OUTPUT points-list's size
  *p_num_points_array = n_steps;

  return out_point_list;
}

mroc_point* getLinerInterpolationWithPointsList(\
    mroc_point* const IN p_points, \
    const int IN num_preset_points, \
    int* OUT num_points_array) {
  CHECKGE(num_preset_points, 2);

  // OUT VALUE
  int num_gathered_points = 0;
  mroc_point* p_gathered_points = NULL;
  //
  const int num_segments = num_preset_points-1;

  // malloc each segment's result
  mroc_point** psp_segments_array = (mroc_point**)malloc(num_segments*sizeof(mroc_point));
  int* sp_segments_points_num = (int*)malloc(num_segments*sizeof(int));

  // get each segment's result
  for(int i=0; i<num_segments; ++i) {
    mroc_point* p_start_pt = &(p_points[i]);
    mroc_point* p_end_pt = &(p_points[i+1]);
    // key-function
    psp_segments_array[i] = getLinearInterpolationWith2Points(\
        p_start_pt, p_end_pt, \
        &(sp_segments_points_num[i])
      );
  }

  // re-organize each segment's result into
  for(int i=0; i<num_segments; ++i) {
    num_gathered_points += sp_segments_points_num[i];
  }
  p_gathered_points = (mroc_point*)malloc(num_gathered_points*sizeof(mroc_point));
  int num_gathering = 0;
  for(int i=0; i<num_segments; ++i) {
    memcpy(&(p_gathered_points[num_gathering]), \
        psp_segments_array[i],
        sp_segments_points_num[i]*sizeof(mroc_point));
    num_gathering += sp_segments_points_num[i];
    // TODO: understand memcpy_s()
  }

  // disposal each segment's array
  free(sp_segments_points_num);
  for(int i=0; i<num_segments; ++i) {
    free(psp_segments_array[i]);
  }

  // prepare OUT VALUE
  *num_points_array = num_gathered_points;
  return p_gathered_points;
}
