#ifndef PROCESSA_IMAGEM_H
#define PROCESSA_IMAGEM_H

#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>
#include <iostream>
#include <string>
#include <math.h>
#include <list>

using namespace std;
using namespace cv;


namespace PROCESSA_IMAGEM
{

Mat openImage ( const string& local );

void saveImage ( const Mat& resultado, String nome );

void showImage ( const Mat& resultado );

Mat gray ( const Mat& image );

Mat grayPonderada ( const Mat& image );

Mat negative ( const Mat& image );

Mat limiarizacao ( const Mat& image, int L );

Mat sum ( const  Mat& image, const Mat& image1 );
Mat sum1 ( const  Mat& image, const Mat& image1 );

Mat sumPonderada ( const  Mat& image1, const Mat& image2, uchar p1, uchar p2 );
Mat sumPonderada1 ( const  Mat& image1, const Mat& image2, uchar p1, uchar p2 );

Mat minus_ ( const Mat& image, const Mat& image1 );
Mat minus1_ ( const Mat& image, const Mat& image1 );

Mat convolucao ( const Mat& image, float mascara[100] );

Mat dilatacao ( const Mat& image, float mascara[100] );

Mat erosao ( const Mat& image, float mascara[100] );

Mat BoundEXT( const Mat& image, float mascara[100] );

Mat BoundINT( const Mat& image, float mascara[100] );

Mat gradiente_morfologico( const Mat& image, float mascara[100] );

Mat abertura( const Mat& image, float mascara[100] );

Mat fechamento( const Mat& image, float mascara[100] );

Mat isolar_canais( const Mat& image, int cor);

Mat incrementar( const Mat& image, int cor, uchar incremento);

Mat zoom_in(const Mat& image);

Mat zoom_out(const Mat& image);

void histograma(const Mat& image);

void info_pixel(Mat& image, String nomeTela);
void on_mouse( int e, int x, int y, int d, void *ptr );




};


#endif
