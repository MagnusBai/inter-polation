#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "utils.h"

#define DISPLAY_MODE    0x01
#define IMAGE_SAVE_MODE 0x02
#define OUTPUT_MODE (DISPLAY_MODE)

void test_interpolation_on_image() {
  using namespace cv;
  Mat im(640, 480, CV_8UC1);
  imshow("1", im); waitKey(0);
}


int main() {
  mroc_point start_pt;
  start_pt.x = 0; start_pt.y = 0;
  mroc_point end_pt;
  end_pt.x = 30; end_pt.y = 50;

  getInterpolationOnImage(NULL, 100, 100, &start_pt, &end_pt, (unsigned char)200);
  // test_interpolation_on_image();

  return EXIT_SUCCESS;
}
