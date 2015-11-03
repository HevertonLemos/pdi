#include "Roberts_.h"

Roberts_::Roberts_(const Mat& fonte)
{
 this->fonte = fonte;
 result = executa(this->fonte);
}


// Mat Roberts_::executa(const Mat& image)
// {
//   Mat result(image.rows, image.cols, CV_8UC3, Scalar(0,0,0));
// 
//   float mascara1[4] = {
// 			0,1,
// 			-1,0
// 			};
// 
//   float mascara2[4] = {
// 			1,0,
// 			0,-1
// 			};
// 
//   for(int i=1; i<image.cols; i++)
//   {
//     for(int j=1; j<image.rows; j++)
//     {
//       int Gx = 0;
//       int Gy = 0;
//       for(int x=-1; x<=0; x++)
//       {
// 	for(int y=-1; y<=0; y++)
// 	{ 
// 	  Gx = Gx + (image.at<Vec3b>(y+j,x+i)[0] * mascara1[(y+1)*2+(x+1)]); //(linha+1) *qtd_linha + (coluna+1)
// 	  Gy = Gy + (image.at<Vec3b>(y+j,x+i)[0] * mascara2[(y+1)*2+(x+1)]); //(linha+1) *qtd_linha + (coluna+1)
// 	}
//       }
//       int G = sqrt((Gx*Gx) + (Gy*Gy));
//       G = abs(G);
//       if(G >= 255)
// 	G = 255;
//       if(G <= 0)
// 	G = 0;
//       
//       for(int k=0; k<3; k++)
//       {
// 	result.at<Vec3b>(j,i)[k] = G;
//       }
//     }
//   }
//   return result;
// }
Mat Roberts_::executa(const Mat& image)
{
  Mat result(image.rows, image.cols, CV_8UC1 );

  float mascara1[4] = {
			0,1,
			-1,0
			};

  float mascara2[4] = {
			1,0,
			0,-1
			};

  for(int i=1; i<image.cols; i++)
  {
    for(int j=1; j<image.rows; j++)
    {
      int Gx = 0;
      int Gy = 0;
      for(int x=-1; x<=0; x++)
      {
	for(int y=-1; y<=0; y++)
	{ 
	  Gx = Gx + (image.at<uchar>(y+j,x+i) * mascara1[(y+1)*2+(x+1)]); //(linha+1) *qtd_linha + (coluna+1)
	  Gy = Gy + (image.at<uchar>(y+j,x+i) * mascara2[(y+1)*2+(x+1)]); //(linha+1) *qtd_linha + (coluna+1)
	}
      }
      int G = sqrt((Gx*Gx) + (Gy*Gy));
      G = abs(G);
      if(G >= 255)
	G = 255;
      if(G <= 0)
	G = 0;
      
      result.at<uchar>(j,i) = G;
    }
  }
  return result;
}




Mat Roberts_::getResult()
{
  return result;
}
