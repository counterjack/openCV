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
