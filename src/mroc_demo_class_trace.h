#ifndef MROC_MROC_DEMO_CLASS_TRACE_HEADER
#define MROC_MROC_DEMO_CLASS_TRACE_HEADER

#include "utils.h"
#include "mroc_interpolation.h"

#ifdef __cplusplus
extern "C" {
#endif

class MrocTrace {
public:
  MrocTrace(const int col, const int row);
  ~MrocTrace();
  static int genRandomBetween(const int num1, const int num2);
  mroc_point* getNextPoint();

protected:
  int m_pt_index;

  mroc_point const_start_pt;
  mroc_point const_end_pt;
  mroc_segment const_4_edge[4];
  int const_interval;
  mroc_point* p_const_trace_pt;
  int const_num_trace_pt;
};

#ifdef __cplusplus
}   // extern "C"
#endif

#endif  // MROC_INTERPOLATION_HEADER