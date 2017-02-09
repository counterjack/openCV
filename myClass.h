#include "myHeaders.h"

class myOpenCV {
private:
  Mat input_image;
  Mat output_image;

public:
  myOpenCV (Mat I);
  // virtual ~myOpenCV ();
  void showImage(const string title);

};

extern myOpenCV::myOpenCV(Mat I){
  input_image = I;
}

extern void myOpenCV::showImage(const string title){
  namedWindow(title, CV_WINDOW_AUTOSIZE);
  imshow(title, input_image);
}
