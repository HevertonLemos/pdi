#ifndef ROBERTS__H
#define ROBERTS__H

#include "ProcessaImagem.h"

using namespace std;
using namespace cv;

class Roberts_
{
  public:
    Roberts_(const Mat& fonte);
    Mat executa(const Mat& image);
    Mat getResult();
    
  private:
    Mat fonte;
    Mat result;
    
};


#endif