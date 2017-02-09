opencv Tutorial so far
######################

#Define I_Image "Input Image"
#Define O_Image "Output Image"
#Define I[1-9]+ "Input Image [1-9]+"
#Define O[1-9]+ "Output Image [1-9]+"

# How to Compile and run opencv file

1. Create a project folder , create a .cpp file , create a CMakeLists.txt
2. Then run `cmake .`
3. then run `make`
4. Run the executable

# Basic Header files

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

# Basic DataTypes

1. Mat(Class) , all images are readed in this datatype


# Basic Functions

1. To read image = imread(IMAGE_PATH, Options) => Options - CV_LOAD_IMAGE_COLOR or CV_LOAD_IMAGE_GRAY
2. To create a window = namedWindow("Title", Options) => Options - CV_WINDOW_AUTOSIZE
3. To show image = imshow("Heading", Image object)
4. 2D Sharpening = filter2D(I_Image, O_Image, I_Image.depth(), kernel)
5. Linear Blending 2 Image = addWeighted(I1, alpha, I2, 1 - alpha, gamma , O_Image)
6.
