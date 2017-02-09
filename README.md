# My opencv basics

### How to Compile and run opencv file

1. Create a project folder , create a .cpp file , create a CMakeLists.txt
2. Then run `cmake .`
3. then run `make`
4. Run the executable


### My codes Header files
`#include <opencv2/core/core.hpp>`<br>
`#include <opencv2/highgui/highgui.hpp>`<br>
`#include <opencv2/imgproc/imgproc.hpp>`<br>

### My codes defined preprocessors patterns
`#Define I_Image "Input Image"`<br>
`#Define O_Image "Output Image"`<br>
`#Define I[1-9]+ "Input Image [1-9]+"`<br>
`#Define O[1-9]+ "Output Image [1-9]+"`<br>

### Functions in this project so far

1. `myReadImage(Mat object, read options)`

  Use this function when we have to read image
2. `myShowImage(image title, Mat object)`

  Use this function when we have to show image with a title
