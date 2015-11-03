#include "Sobel_.h"

Sobel_::Sobel_(const Mat& fonte)
{
 this->fonte = fonte;
 result = executa(this->fonte);
}


Mat Sobel_::executa(const Mat& image)
{
  Mat resultado(image.rows, image.cols, CV_8UC1 );

  float mascara1[9] = {
			 1, 2, 1,
			 0, 0, 0,
			-1,-2,-1
			};
  float mascara2[9] = {
			1, 0,-1,
			2, 0,-2,
			1, 0,-1
			};

  for(int i=1; i<image.cols-1; i++)
  {
    for(int j=1; j<image.rows-1; j++)
    {
      int Gx = 0;
      int Gy = 0;
      for(int x=-1; x<=1; x++)
      {
	for(int y=-1; y<=1; y++)
	{ 
	  Gx = Gx + (image.at<uchar>(y+j,x+i) * mascara1[(y+1)*3+(x+1)]); //(linha+1) *qtd_linha + (coluna+1)
	  Gy = Gy + (image.at<uchar>(y+j,x+i) * mascara2[(y+1)*3+(x+1)]); //(linha+1) *qtd_linha + (coluna+1)
	}
      }
      int G = abs(Gx) + abs(Gy);
      if(G >= 255)
	G = 255;
      if(G <= 0)
	G=0;
      
      resultado.at<uchar>(j,i) = G;
     }
  }
  return resultado;
}




Mat Sobel_::getResult()
{
  return result;
}
