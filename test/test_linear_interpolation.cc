#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "mroc_interpolation.h"

#define DISPLAY_MODE    0x01
#define IMAGE_SAVE_MODE 0x02
#define OUTPUT_MODE (DISPLAY_MODE)

int test_2points_interpolation_txt() {
  printf("%s:L%d  test_2points_interpolation_txt()\n", __FILE__, __LINE__);

  mroc_point start_pt;
  start_pt.x = 0; start_pt.y = 0;
  mroc_point end_pt;
  end_pt.x = 30; end_pt.y = 50;

  // prepare a number and a stray-pointer-array
  int num_points;
  mroc_point* sp_points_list = getLinearInterpolationWith2Points(\
        &start_pt, &end_pt, &num_points);

  printf("size of list is: %d\n", num_points);
  for(int i=0; i<num_points; ++i) {
    printf("%d: (%d, %d)\t", i, sp_points_list[i].x, sp_points_list[i].y);
  }
  printf("\n");

  // disposal stray-pointer-array
  free(sp_points_list);

  return EXIT_SUCCESS;
}

int test_multipoints_interpolation_txt1() {
  printf("%s:L%d  test_multipoints_interpolation_txt1()\n", __FILE__, __LINE__);

  mroc_point pt[2];
  pt[0].x = 20; pt[0].y = 20;
  pt[1].x = 50; pt[1].y = 20;

  // prepare a number and a stray-pointer-array
  int num_points;
  mroc_point* sp_points_list = getLinerInterpolationWithPointsList(\
        (mroc_point*)pt, 2, &num_points);

  printf("size of list is: %d\n", num_points);
  for(int i=0; i<num_points; ++i) {
    printf("%d: (%d, %d)\t", i, sp_points_list[i].x, sp_points_list[i].y);
  }
  printf("\n");

  // disposal stray-pointer-array
  free(sp_points_list);

  return EXIT_SUCCESS;
}

int test_multipoints_interpolation_txt2() {
  printf("%s:L%d  test_multipoints_interpolation_txt2()\n", __FILE__, __LINE__);

  mroc_point pt[4];
  pt[0].x = 20; pt[0].y = 20;
  pt[1].x = 50; pt[1].y = 20;
  pt[2].x = 50; pt[2].y = 50;
  pt[3].x = 20; pt[3].y = 50;

  // prepare a number and a stray-pointer-array
  int num_points;
  mroc_point* sp_points_list = getLinerInterpolationWithPointsList(\
        (mroc_point*)pt, 4, &num_points);

  printf("size of list is: %d\n", num_points);
  for(int i=0; i<num_points; ++i) {
    printf("%d: (%d, %d)\t", i, sp_points_list[i].x, sp_points_list[i].y);
  }
  printf("\n");

  // disposal stray-pointer-array
  free(sp_points_list);

  return EXIT_SUCCESS;
}

int test_multipoints_interpolation_opencv() {
  printf("%s:L%d  test_multipoints_interpolation_txt2()\n", __FILE__, __LINE__);

  const int COLS = 100; const int ROWS = 100;
  cv::Mat im(COLS, ROWS, CV_8UC1, \
      cv::Scalar((unsigned char)255));

  mroc_point pt[5];
  pt[0].x = 20; pt[0].y = 20;
  pt[1].x = 50; pt[1].y = 20;
  pt[2].x = 50; pt[2].y = 50;
  pt[3].x = 20; pt[3].y = 50;
  pt[4].x = 20; pt[4].y = 20;

  // prepare a number and a stray-pointer-array
  int num_points;
  mroc_point* sp_points_list = getLinerInterpolationWithPointsList(\
        (mroc_point*)pt, 5, &num_points);

  printf("size of list is: %d\n", num_points);
  for(int i=0; i<num_points; ++i) {
    // printf("%d: (%d, %d)\t", i, sp_points_list[i].x, sp_points_list[i].y);
    ((unsigned char*)im.data)[sp_points_list[i].y*COLS+sp_points_list[i].x] = (unsigned char)0;
  }

  // cv::imshow("1", im);
  // cv::waitKey(0);
  cv::imwrite("build/test_multipoints_interpolation_opencv.png", im);
  printf("saved to build/test_multipoints_interpolation_opencv.png\n");

  // disposal stray-pointer-array
  free(sp_points_list);

  return EXIT_SUCCESS;
}

int main() {
  test_2points_interpolation_txt();
  test_multipoints_interpolation_txt1();
  test_multipoints_interpolation_txt2();
  test_multipoints_interpolation_opencv();

  return EXIT_SUCCESS;
}
