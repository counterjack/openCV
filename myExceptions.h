/*
* Author: Vipin Chaudhary
* github: https://github.com/vipin14119/openCV
*/


struct ImageNotSameException : public exception {
  const char * what() const throw() {
    return "Image Size or Type not equal";
  }
};

struct InvalidImageException : public exception {
  const char * what() const throw() {
    return "Invalid Image or Invalid Image Path";
  }
};
