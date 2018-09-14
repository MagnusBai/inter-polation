#include "mroc_demo_class_trace.h"

#include <time.h>
#include <math.h>   // roundf

static int MrocTrace::genRandomBetween(const int num1, const int num2) {
  // srand(time(NULL)); // use current time as seed for random generator

  int lower_num = min(num1, num2);
  int upper_num = max(num1, num2);
  if(lower_num==upper_num) {
    return lower_num;
  }

  int result = rand()%(upper_num-lower_num) + lower_num;
  return result;
}

MrocTrace::MrocTrace(const int col, const int row) {
  { // setting 4 edges
    const_4_edge[0].start_pt.x = 0;
    const_4_edge[0].start_pt.y = 0;
    const_4_edge[0].end_pt.x = col-1;
    const_4_edge[0].end_pt.y = 0;
    const_4_edge[1].start_pt.x = col-1;
    const_4_edge[1].start_pt.y = 0;
    const_4_edge[1].end_pt.x = col-1;
    const_4_edge[1].end_pt.y = row-1;
    const_4_edge[2].start_pt.x = col-1;
    const_4_edge[2].start_pt.y = row-1;
    const_4_edge[2].end_pt.x = 0;
    const_4_edge[2].end_pt.y = row-1;
    const_4_edge[3].start_pt.x = 0;
    const_4_edge[3].start_pt.y = row-1;
    const_4_edge[3].end_pt.x = 0;
    const_4_edge[3].end_pt.y = 0;
  }
  int first_edge_index = genRandomBetween(0, 4);
  int second_edge_index = genRandomBetween(0, 4);
  while(second_edge_index==first_edge_index) {
    second_edge_index = genRandomBetween(0, 4);
  }
  // printf("%d, %d \n", first_edge_index, second_edge_index);

  const_start_pt.x = genRandomBetween( \
      const_4_edge[first_edge_index].start_pt.x, \
      const_4_edge[first_edge_index].end_pt.x);
  const_start_pt.y = genRandomBetween( \
      const_4_edge[first_edge_index].start_pt.y, \
      const_4_edge[first_edge_index].end_pt.y);
  const_end_pt.x = genRandomBetween( \
      const_4_edge[second_edge_index].start_pt.x, \
      const_4_edge[second_edge_index].end_pt.x);
  const_end_pt.y = genRandomBetween( \
      const_4_edge[second_edge_index].start_pt.y, \
      const_4_edge[second_edge_index].end_pt.y);
  // printf("(%d, %d), (%d, %d)\n", const_start_pt.x, const_start_pt.y, const_end_pt.x, const_end_pt.y);

  const_interval = genRandomBetween(1, 10);

  int num_all_pt = 0;
  // stray pointer #1
  mroc_point* p_all_pt = getLinearInterpolationWith2Points(\ 
      &const_start_pt, \
      &const_end_pt,
      &num_all_pt);
  p_const_trace_pt = samplePointsByCertainInterval( \
      p_all_pt, \
      num_all_pt, \
      const_interval, \
      &const_num_trace_pt);
  free(p_all_pt);

  m_pt_index = 0;
}

MrocTrace::~MrocTrace() {
  if(p_const_trace_pt!=NULL) {
    free(p_const_trace_pt);
  }
}

mroc_point* MrocTrace::getNextPoint() {
  printf(">> %d / %d \n", m_pt_index, const_num_trace_pt);
  if(m_pt_index<const_num_trace_pt) {
    mroc_point* p_ret = &(p_const_trace_pt[m_pt_index]);
    ++m_pt_index;
    return p_ret;
  }
  else {
    return NULL;
  }
}