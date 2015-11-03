#ifndef ROBINSON__H
#define ROBINSON__H

#include "ProcessaImagem.h"

using namespace std;
using namespace cv;

class Robinson_
{
  public:
    Robinson_(const Mat& fonte);
    Mat executa(const Mat& image);
    Mat getResult();
    void quickSort(int valor[], int esquerda, int direita);
    
  private:
    Mat fonte;
    Mat result;
    
};


#endif