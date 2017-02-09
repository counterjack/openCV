#include "myHeaders.h"
#include "myFunctions.h"
#include "myClass.h"

/*
* Author: Vipin Chaudhary
* github: vipin14119
*/

using namespace vipin;  // my custom namespace to prevent function name conflicts with other functions

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cerr << "Parameter wrong" << '\n' << "Usage : ./main [ARG] "<< '\n';
    return -1;
  }

  Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
  Mat I = myReadImage(argv[1], CV_LOAD_IMAGE_COLOR);
  // Mat O = my2DFilter(&I, &kernel);
  // myShowImage("My Image", O);

  OpenCV object(I);
  object.showImage("myImage");

  // filter2D(I, J, I.depth(), kernel);

  double alp = 0.5;
  Mat I1, I2, D;

  I1 = imread("./images/2.jpg");
  I2 = imread("./images/6.jpg");

  // Mat new_image = Mat::zeros(I1.size(), I1.type());
  //
  // for (size_t i = 0; i < I1.rows; i++) {
  //   for (size_t j = 0; j < I1.cols; j++) {
  //     for (size_t k = 0; k < 3; k++) {
  //       new_image.at<Vec3b>(i,j)[k] = saturate_cast<uchar>(2.2*I1.at<Vec3b>(i,j)[k] + 50);
  //     }
  //   }
  // }

  // myShowImage("My Image", myReadImage(argv[1], CV_LOAD_IMAGE_COLOR));
  // std::cout << "M = " << myCreateMat(3, 3, 1) << '\n';
  // namedWindow("Original image", CV_WINDOW_AUTOSIZE);
  // namedWindow("New image", CV_WINDOW_AUTOSIZE);
  // // addWeighted(I1, alp, I2, 1 - alp, 0.0, D);
  // imshow("Original image", readImage("./images/2.jpg", CV_LOAD_IMAGE_COLOR));
  // imshow("New image", new_image);
  waitKey(0);

  // if (!s || !divideWith) {
  //   cout << "Invalid number entered for dividing" << '\n';
  //   return -1;
  // }
  // uchar table[256];
  // for(int i=0;i<256;i++){
  //   table[i] = (uchar)(divideWith * (i/divideWith));
  // }
  //
  // Mat M(1, 256, CV_8U);
  // uchar *p = M.data;
  // for (size_t i = 0; i < 256; i++) {
  //   p[i] = table[i];
  // }
  // const int times = 100;
  // double t = (double)getTickCount();
  //
  // for (size_t i = 0; i < times; i++) {
  //   LUT(I, M, J);
  // }
  //
  // t = 1000*((double)getTickCount() - t)/getTickFrequency();
  // t /= times;
  // std::cout << "Time passed = "<< t << " milliseconds " << '\n';



  return 0;
}
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
