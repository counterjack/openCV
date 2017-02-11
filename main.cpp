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
  Mat I, I1, I2, O, kernel;

  std::cout << "1. 2D Filter" << '\n';
  std::cout << "2. 2D Blending" << '\n';
  std::cout << "3. 2D Transformation" << '\n';
  std::cout << "4. 2D Atom" << '\n';
  std::cout << "Enter your Number = ";

  std::cin >> choice;

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

        // Mat atom = myCreateMat(SIZE, SIZE, 3, "zeros");
        Mat atom(SIZE, SIZE, CV_8UC3, Scalar(240, 240, 240));
        Mat rook = myCreateMat(SIZE, SIZE, 3, "zeros");

        // Drawing atom
        MyEllipse(&atom, (double)90);
        MyEllipse(&atom, (double)0);
        MyEllipse(&atom, (double)45);
        MyEllipse(&atom, (double)-45);
        MyFilledCircle(&atom, Point( SIZE/2, SIZE/2) );

        // Outer Square
        MyLine(&atom, Point( 100, 100), Point( SIZE-100, 100));
        MyLine(&atom, Point( 100, 100), Point( 100, SIZE-100));
        MyLine(&atom, Point( 100, SIZE-100), Point( SIZE-100, SIZE-100));
        MyLine(&atom, Point( SIZE-100, 100), Point( SIZE-100, SIZE-100));

        // Outer Square
        MyLine(&atom, Point( 75, 75), Point( SIZE-75, 75));
        MyLine(&atom, Point( 75, 75), Point( 75, SIZE-75));
        MyLine(&atom, Point( 75, SIZE-75), Point( SIZE-75, SIZE-75));
        MyLine(&atom, Point( SIZE-75, 75), Point( SIZE-75, SIZE-75));

        // Inner Square
        MyLine(&atom, Point( 50, 50), Point( SIZE-50, 50));
        MyLine(&atom, Point( 50, 50), Point( 50, SIZE-50));
        MyLine(&atom, Point( 50, SIZE-50), Point( SIZE-50, SIZE-50));
        MyLine(&atom, Point( SIZE-50, 50), Point( SIZE-50, SIZE-50));
        // MyLine(&atom, Point( 100, 100), Point( SIZE-100, 100));
        // MyLine(&atom, Point( 100, 100), Point( SIZE-100, 100));
        // std::cout << "Atom = " << atom << '\n';
        namedWindow(drawing1, CV_WINDOW_AUTOSIZE);
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
