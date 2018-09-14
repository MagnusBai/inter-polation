
#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "mroc_interpolation.h"
#include "mroc_demo_class_trace.h"

int testTrace() {
  using namespace cv;

  const int col = 640; const int row = 480;
  Mat im_canvas(row, col, CV_8UC1);
  im_canvas.setTo(Scalar((unsigned char)255));

  MrocTrace m(col, row);

  for(mroc_point* p_pt=m.getNextPoint(); true; p_pt=m.getNextPoint()) {
    if(p_pt==NULL) { break; }
    // printf("(%d, %d)\n", p_pt->x, p_pt->y);

    Mat out = im_canvas.clone();
    circle(out, Point(p_pt->x, p_pt->y), 2, Scalar(0), 2);

    imshow("1", out);
    waitKey(0);
  }


  return EXIT_SUCCESS;
}


int main() {

  testTrace();

  return EXIT_SUCCESS;
}
