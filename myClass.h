#include "myHeaders.h"

/*
* Author: Vipin Chaudhary
* github: vipin14119
*/


namespace vipin{
  class OpenCV {
  private:
    Mat input_image;
    Mat output_image;

  public:
    OpenCV (Mat I);
    // virtual ~myOpenCV ();
    void showImage(const string title);

  };

  extern OpenCV::OpenCV(Mat I){
    input_image = I;
  }

  extern void OpenCV::showImage(const string title){
    namedWindow(title, CV_WINDOW_AUTOSIZE);
    imshow(title, input_image);
  }
}
