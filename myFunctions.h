/*
* Author: Vipin Chaudhary
* github: vipin14119
*/

/* Custom Functions declaration Starts */

extern Mat myReadImage(string title, int option);
extern void myShowImage(const string title, const  Mat Image);
extern Mat myCreateMat(const int rows, const int cols, const  int depth, const char* mat_type = "default");
extern Mat my2DFilter(const Mat *input_image, const Mat *kernel);

/* Custom Functions declaration Ends */
