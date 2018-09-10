#ifndef MROC_INTERPOLATION_HEADER
#define MROC_INTERPOLATION_HEADER

#include "utils.h"

#ifdef __cplusplus
extern "C" {
#endif

// get internal-points-list of 2 previously set points
mroc_point* getLinearInterpolationWith2Points( \
    mroc_point* const IN p_start_pt, \
    mroc_point* const IN p_end_pt, \
    int* OUT p_num_points_array);

// get internal-points-list of a list of previusly set points
mroc_point* getLinerInterpolationWithPointsList(\
    mroc_point* const IN p_points, \
    const int IN num_preset_points, \
    int* OUT num_points_array);

#ifdef __cplusplus
}   // extern "C"
#endif

#endif  // MROC_INTERPOLATION_HEADER

