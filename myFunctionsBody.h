#include "myFunctionsDeclarations.h"


Mat myReadImage(const string path, int option){
  Mat Image = imread(path, option);
  if (!Image.data) {
    throw InvalidImageException();
  }
  return Image;
}

void myShowImage(const string title, const Mat Image){
  namedWindow(title, CV_WINDOW_NORMAL);
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

Mat myBasicLinearTransform(const Mat* I, const double alpha, const double beta){
  Mat O = Mat::zeros(I->size(), I->type());
  for (size_t i = 0; i < I->rows; i++) {
    for (size_t j = 0; j < I->cols; j++) {
      for (size_t k = 0; k < 3; k++) {
        O.at<Vec3b>(i,j)[k] = saturate_cast<uchar>(alpha*I->at<Vec3b>(i,j)[k] + beta);
      }
    }
  }
  return O;
}
void MyEllipse(Mat *img, const double angle){
  int thickness = 2;
  int lineType = 10;
  ellipse(
    *img,
    Point( SIZE/2, SIZE/2 ),
    Size( SIZE/4, SIZE/16 ),
    angle,
    0,
    360,
    Scalar( 255, 0, 0 ),
    thickness,
    lineType
  );
}
void MyPolygon(Mat *img){

}
void MyLine(Mat *img, const Point *start, const Point *end){

}
void MyFilledCircle(Mat *img, const Point center){
  circle(
    *img,
    center,
    SIZE/32,
    Scalar( 0, 0, 255 ),
    FILLED,
    LINE_8
  );
}
