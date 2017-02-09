#include "myHeaders.h"
#include "myFunctions.h"
#include "myClass.h"

/*
* Author: Vipin Chaudhary
* github: https://github.com/vipin14119/openCV
*/

typedef Mat VipinImageObject;

#ifndef MAX
#define MAX 100
#endif

using namespace vipin;  // my custom namespace to prevent function name conflicts with other functions

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    std::cerr << "Parameter wrong" << '\n' << "Usage : ./main [ARG] "<< '\n';
    return -1;
  }

  Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
  Mat I = myReadImage(argv[1], CV_LOAD_IMAGE_COLOR);

  vipin::OpenCV object(&I);
  object.setKernel(&kernel);

  Mat O = object.filter2d();
  // myShowImage("Filter 2D", O);

  double alp = 0.5;
  Mat I1, I2;
  I1 = imread(argv[1], CV_LOAD_IMAGE_COLOR);
  I2 = imread(argv[2], CV_LOAD_IMAGE_COLOR);
  try{
    O = myApply2DBlend(&I1, &I2, alp);
    myShowImage("2D Blending", O);
  }
  catch(const char* e){
    std::cerr << "ERROR : "<< e << '\n';
    return -1;
  }
  catch(ImageNotSameException &e){
    std::cerr << "ERROR : "<<e.what() << '\n';
    return -1;
  }

  myShowImage("Basic Transformation", myBasicLinearTransform(&I1, 2.2, 50));
  // Mat new_image = Mat::zeros(I1.size(), I1.type());
  //
  // for (size_t i = 0; i < I1.rows; i++) {
  //   for (size_t j = 0; j < I1.cols; j++) {
  //     for (size_t k = 0; k < 3; k++) {
  //       new_image.at<Vec3b>(i,j)[k] = saturate_cast<uchar>(2.2*I1.at<Vec3b>(i,j)[k] + 50);
  //     }
  //   }
  // }

  waitKey(0);
  return 0;
}
