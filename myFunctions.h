#include "myExceptions.h"
/*
* Author: Vipin Chaudhary
* github: https://github.com/vipin14119/openCV
*/

/* Custom Functions declaration Starts */

extern Mat myReadImage(string title, int option);
extern void myShowImage(const string title, const  Mat Image);
extern Mat myCreateMat(const int rows, const int cols, const  int depth, const char* mat_type = "default");
extern Mat my2DFilter(const Mat *input_image, const Mat *kernel);
extern Mat myApply2DBlend(Mat *I1, Mat *I2, const double alpha);

/* Custom Functions declaration Ends */


Mat myReadImage(const string path, int option){
  Mat Image = imread(path, option);
  return Image;
}

void myShowImage(const string title, const Mat Image){
  namedWindow(title, CV_WINDOW_AUTOSIZE);
  imshow(title, Image);
}

Mat myCreateMat(const int rows, const int cols, const int depth, const char* mat_type){

  if (strcmp("ones", mat_type) == 0) {
    return Mat::ones(rows, cols, CV_8UC(depth));
  }
  else if (strcmp("zeros", mat_type) == 0) {
    return Mat::zeros(rows, cols, CV_8UC(depth));
  }
  else if (strcmp("eye", mat_type) == 0) {
    return Mat::eye(rows, cols, CV_8UC(depth));
  }
  else {
    Mat M(rows, cols, CV_8UC(depth), Scalar::all(255));
    return M;
  }

}

Mat my2DFilter(const Mat *input_image, const Mat *kernel){
  Mat Output_image;
  std::cout << "Depth = " << input_image->depth() << '\n';
  filter2D(*input_image, Output_image, (*input_image).depth(), *kernel);
  return Output_image;
}

Mat myApply2DBlend(Mat *I1, Mat *I2, const double alpha){
  Mat O;
  if(I1->size() != I2->size() || I1->type() != I2->type()){
    throw ImageNotSameException();
  }
  addWeighted(*I1, alpha, *I2, 1 - alpha, 0.0, O);
  std::cout << "Came here" << '\n';
  return O;
}
