#include "myHeaders.h"
#include "myExceptions.h"

#ifndef SIZE
#define SIZE 600
#endif


/*
* Author: Vipin Chaudhary
* github: https://github.com/vipin14119/openCV
*/

/* Custom Functions declaration Starts */

// Image IO functions
extern Mat myReadImage(string title, int option);
extern void myShowImage(const string title, const  Mat Image);

// 2D Image operations functions
extern Mat myCreateMat(const int rows, const int cols, const  int depth, const char* mat_type = "default");
extern Mat my2DFilter(const Mat *input_image, const Mat *kernel);
extern Mat myApply2DBlend(Mat *I1, Mat *I2, const double alpha);
extern Mat myBasicLinearTransform(const Mat* I, const double alpha, const double beta);

// 2D Drawing functions
extern void MyEllipse(Mat *img, const double *angle);
extern void MyPolygon(Mat *img);
extern void MyLine(Mat *img, const Point start, const Point end);
extern void MyFilledCircle(Mat *img, const Point *center);

/* Custom Functions declaration Ends */
