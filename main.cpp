#include "myHeaders.h"
#include "myFunctionsBody.h"
#include "myClass.h"

/*
* Author: Vipin Chaudhary
* github: https://github.com/vipin14119/openCV
*/

typedef Mat VipinImageObject;

using namespace vipin;  // my custom namespace to prevent function name conflicts with other functions

int main(int argc, char const *argv[]) {
  // if (argc != 3) {
  //   std::cerr << "Parameter wrong" << '\n' << "Usage : ./main [ARG] "<< '\n';
  //   return -1;
  // }

  int choice;
  std::cin >> choice;

  Mat I, I1, I2, O, kernel;

  switch (choice) {
    case 1:
      {
        // Apply 2D filter using my class
        string image_path;
        std::cin >> image_path;
        try{
          kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
          I = myReadImage(image_path, CV_LOAD_IMAGE_COLOR);

          vipin::OpenCV object(&I);
          object.setKernel(&kernel);

          O = object.filter2d();
          myShowImage("Filter 2D", O);
          waitKey(0);
        }
        catch(InvalidImageException &e){
          std::cerr << "ERROR : "<<e.what() << '\n';
        }

        break;
      }
    case 2:
      {
        double alp = 0.5;
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
        break;
      }
    case 3:
      {
        myShowImage("Basic Transformation", myBasicLinearTransform(&I1, 2.2, 50));
        waitKey(0);
        break;
      }
    case 4:
      {
        char drawing1[] = "Atom Image";
        char drawing2[] = "Rook Image";

        Mat atom = myCreateMat(SIZE, SIZE, 3, "zeros");
        Mat rook = myCreateMat(SIZE, SIZE, 3, "zeros");

        // Drawing atom
        MyEllipse(&atom, (double)90);
        MyEllipse(&atom, (double)0);
        MyEllipse(&atom, (double)45);
        MyEllipse(&atom, (double)-45);
        MyFilledCircle(&atom, Point( SIZE/2, SIZE/2) );
        // std::cout << "Atom = " << atom << '\n';
        imshow( drawing1, atom );
        waitKey(0);
        break;
      }
    default:
      //
      std::cout << "/* message */" << '\n';
      break;
  }
  return 0;
}
