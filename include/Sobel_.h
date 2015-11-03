#ifndef SOBEL__H
#define SOBEL__H

#include "ProcessaImagem.h"

using namespace std;
using namespace cv;

class Sobel_
{
  public:
    Sobel_(const Mat& fonte);
    Mat executa(const Mat& image);
    Mat getResult();
    
  private:
    Mat fonte;
    Mat result;
    
};


#endif