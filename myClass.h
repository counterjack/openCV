#include "myHeaders.h"

/*
* Author: Vipin Chaudhary
* github: vipin14119
*/


namespace vipin {
  
  class OpenCV {
  private:
    Mat *input_image;
    Mat *output_image;
    Mat *kernel;

  public:
    OpenCV(void);
    OpenCV (Mat *I);
    // virtual ~myOpenCV ();
    void showImage(const string title);
    Mat filter2d(void);
    void setKernel(Mat* kern);
    Mat getKernel(void);

  };

  extern OpenCV::OpenCV(Mat *I){
    input_image = I;
  }

  extern void OpenCV::showImage(const string title){
    namedWindow(title, CV_WINDOW_AUTOSIZE);
    imshow(title, *input_image);
  }

  extern void OpenCV::setKernel(Mat *kern){
    kernel = kern;
  }

  extern Mat OpenCV::getKernel(){
    return *kernel;
  }

  extern Mat OpenCV::filter2d(){
    Mat output_image;
    filter2D(*input_image, output_image, input_image->depth(), *kernel);
    return output_image;
  }

}
