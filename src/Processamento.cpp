#include "include/Processamento.h"


Mat Processamento::openImage ( const string& local )
{
    Mat  image;
    image = imread ( local );
    if ( !image.data ) {
        cout << "Sem imagem! \n" << endl;
    }
    return image;
}


void Processamento::saveImage ( const Mat& resultado, String nome )
{
    imwrite ( nome, resultado );
}


void Processamento::showImage ( const Mat& resultado )
{
    namedWindow ( "Display Image" );
    imshow ( "Display Image", resultado );
}

Mat Processamento::gray ( const Mat& image )
{
    Mat resultado ( image.rows, image.cols, CV_8UC1);
    Vec3b rgb;

    for ( int i=0; i<image.cols; i++ ) {
        for ( int j=0; j<image.rows; j++ ) {
            rgb = image.at<Vec3b> ( j,i );
            uchar blue = rgb[0];
            uchar green = rgb[1];
            uchar red = rgb[2];
            uchar result = ( blue + green + red ) /3;
        resultado.at<uchar> ( j,i ) = result;
        }
    }
    return resultado;
}

Mat Processamento::grayPonderada ( const Mat& image )
{
    Mat resultado ( image.rows, image.cols, CV_8UC1 );
    Vec3b rgb;

    for ( int i=0; i<image.cols; i++ ) {
        for ( int j=0; j<image.rows; j++ ) {
            rgb = image.at<Vec3b> ( j,i );
            uchar blue = rgb[0];
            uchar green = rgb[1];
            uchar red = rgb[2];
            uchar result = (blue * 0.114) + (green * 0.587) + (red * 0.299);
            resultado.at<uchar> ( j,i ) = result;
        }
    }
    return resultado;
}

Mat Processamento::negative ( const Mat& image )
{
    Mat resultado ( image.rows, image.cols, CV_8UC3, Scalar ( 0,0,0 ) );
    Vec3b rgb;

    for ( int i=0; i<image.cols; i++ ) {
        for ( int j=0; j<image.rows; j++ ) {
            rgb = image.at<Vec3b> ( j,i );
            for ( int k=0; k<3; k++ ) {
                uchar result = ( 255 - rgb[k] );
                resultado.at<Vec3b> ( j,i ) [k] = result;
            }
        }
    }
    return resultado;
}

Mat Processamento::limiarizacao ( const Mat& image, int L )
{
    Mat resultado ( image.rows, image.cols, CV_8UC1 );
    uchar result;

    for ( int i=0; i<image.cols; i++ )
    {
      for ( int j=0; j<image.rows; j++ )
      {
    if ( image.at<uchar> ( j,i ) > L )
    {
      result = 255;
    }
    else
    {
      result = 0;
    }

    resultado.at<uchar> ( j,i ) = result;
      }
    }
    return resultado;
}

Mat Processamento::sum ( const  Mat& image, const Mat& image1 )
{
    Mat resultado ( image.rows, image.cols, CV_8UC3, Scalar ( 0,0,0 ) );
    Vec3b rgb, rgb1;

    for ( int i=0; i<image.cols; i++ ) {
        for ( int j=0; j<image.rows; j++ ) {
            rgb = image.at<Vec3b> ( j,i );
            rgb1 = image1.at<Vec3b> ( j,i );
            for ( int k=0; k<3; k++ )
        {
        uchar soma = ( rgb[k] + rgb1[k] ) /2;
        if (soma >= 255)
          soma = 255;
        if(soma <= 0)
          soma = 0;
                resultado.at<Vec3b> ( j,i ) [k] = soma;
            }
        }
    }

    return resultado;
}


Mat Processamento::sum1 ( const  Mat& image, const Mat& image1 )
{
    Mat resultado ( image.rows, image.cols, CV_8UC1 );
    uchar rgb, rgb1;

    for ( int i=0; i<image.cols; i++ ) {
        for ( int j=0; j<image.rows; j++ ) {
            rgb = image.at<uchar> ( j,i );
            rgb1 = image1.at<uchar> ( j,i );
        uchar soma = ( rgb + rgb1 ) /2;
        if (soma >= 255)
          soma = 255;
        if(soma <= 0)
          soma = 0;
        resultado.at<uchar> ( j,i ) = soma;
        }
    }

    return resultado;
}


Mat Processamento::sumPonderada ( const  Mat& image1, const Mat& image2, uchar p1, uchar p2 )
{
    Mat resultado ( image1.rows, image1.cols, CV_8UC3, Scalar ( 0,0,0 ) );
    Vec3b rgb1, rgb2;

    for ( int i=0; i<image1.cols; i++ ) {
        for ( int j=0; j<image1.rows; j++ ) {
            rgb1 = image1.at<Vec3b> ( j,i );
            rgb2 = image2.at<Vec3b> ( j,i );
            for ( int k=0; k<3; k++ )
        {
        uchar soma = (rgb1[k] * p1/100) + (rgb2[k] * p2/100);
        if (soma >= 255)
          soma = 255;
        if(soma <= 0)
          soma = 0;
                resultado.at<Vec3b> ( j,i ) [k] = soma;
            }
        }
    }

    return resultado;
}


Mat Processamento::sumPonderada1 ( const  Mat& image1, const Mat& image2, uchar p1, uchar p2 )
{
    Mat resultado ( image1.rows, image1.cols, CV_8UC1 );
    uchar rgb1, rgb2;

    for ( int i=0; i<image1.cols; i++ )
    {
        for ( int j=0; j<image1.rows; j++ )
    {
            rgb1 = image1.at<uchar> ( j,i );
            rgb2 = image2.at<uchar> ( j,i );
        uchar soma = (rgb1 * p1/100) + (rgb2 * p2/100);
        if (soma >= 255)
          soma = 255;
        if(soma <= 0)
          soma = 0;
        resultado.at<uchar> ( j,i ) = soma;
        }
    }

    return resultado;
}


Mat Processamento::minus_ ( const Mat& image, const Mat& image1 )
{
    Mat resultado ( image.rows, image.cols, CV_8UC3, Scalar ( 0,0,0 ));
    Vec3b rgb, rgb1;

    for ( int i=0; i<image.rows; i++ )
    {
        for ( int j=0; j<image.cols; j++ )
    {
      rgb = image.at<Vec3b> ( i,j );
      rgb1 = image1.at<Vec3b> ( i,j );

      for ( int k=0; k<3; k++ )
      {
        int subtracao = rgb[k] - rgb1[k];
// 	    if (subtracao > 255)
// 	      subtracao = 255;
// 	    if(subtracao <= 0)
// 	      subtracao = 0;
          resultado.at<Vec3b> ( i,j ) [k] = abs(subtracao);
      }
        }
    }
    return resultado;
}


Mat Processamento::minus1_ ( const Mat& image, const Mat& image1 )
{
    Mat resultado ( image.rows, image.cols, CV_8UC1);
    uchar rgb, rgb1;
    //char rgb, rgb1;

    for ( int i=0; i<image.cols; i++ )
    {
        for ( int j=0; j<image.rows; j++ )
    {
      rgb = image.at<uchar> ( j,i );
      rgb1 = image1.at<uchar> ( j,i );

      int subtracao = rgb - rgb1;
      resultado.at<uchar> ( j,i ) = abs(subtracao);
        }
    }
    return resultado;
}


Mat Processamento::convolucao ( const Mat& image , float mascara[100] )
{
    Mat resultado ( image.rows, image.cols, CV_8UC1 );

    for ( int i=1; i<image.cols-1; i++ )
    {
      for ( int j=1; j<image.rows-1; j++ )
      {
    uchar result = 0;
    for ( int x=-1; x<=1; x++ )
    {
      for ( int y=-1; y<=1; y++ )
      {
        result = result + ( image.at<uchar> ( y+j,x+i ) * mascara[ ( y+1 ) *3+ ( x+1 )] );
          }
    }
    if(result >= 255)
      result = 255;
    if(result <= 0)
      result = 0;

    resultado.at<uchar> ( j,i ) = result;
      }
    }
    return resultado;
}


Mat Processamento::dilatacao ( const Mat& image, float mascara[100] )
{
  Mat resultado ( image.rows, image.cols, CV_8UC1 );
  uchar result;

  for ( int i=1; i<image.cols-1; i++ )
  {
    for ( int j=1; j<image.rows-1; j++ )
    {
      for ( int x=-1; x<=1; x++ )
      {
    for ( int y=-1; y<=1; y++ )
    {
      if ( image.at<uchar> ( 0+j, 0+i ) != mascara[ ( 0+1 ) *3+ ( 0+1 )] )
      {
        result = image.at<uchar> ( 0+j, 0+i );
      }
      else
      {
        result= image.at<uchar> ( y+j, x+i );
      }

      resultado.at<uchar>( y+j,x+i ) = result;
    }
      }
    }
  }
  return resultado;
}


Mat Processamento::erosao ( const Mat& image, float mascara[100] )
{
  Mat resultado ( image.rows, image.cols, CV_8UC1 );
  uchar result;

  for ( int i=1; i<image.cols-1; i++ )
  {
    for ( int j=1; j<image.rows-1; j++ )
    {
      uchar teste = 0;
      for ( int x=-1; x<=1; x++ )
      {
    for ( int y=-1; y<=1; y++ )
    {
      teste= teste + image.at<uchar> ( y+j, x+i );
    }
      }
      if ( teste != mascara[ ( 0+1 ) *3+ ( 0+1 )] )
      {
    result = 255;
      }
      else
      {
    result = 0;
      }

      resultado.at<uchar> ( j,i ) = result;
    }
  }
  return resultado;
}


// Acha todos os pixels que limitam o objeto pelo lado de fora (contorno externo).
Mat Processamento::BoundEXT( const Mat& image, float mascara[100] )
{
  Mat result ( image.rows, image.cols, CV_8UC1 );
  result = dilatacao(image, mascara);
  result = minus_(result, image);

  return result;
}


//Acha o contorno de interno objetos
Mat Processamento::BoundINT( const Mat& image, float mascara[100] )
{
  Mat result (image.rows, image.cols, CV_8UC1);
  result = erosao(image, mascara);
  result = minus_(image, result);

  return result;
}


Mat Processamento::gradiente_morfologico( const Mat& image, float mascara[100] )
{
  Mat result(image.rows, image.cols, CV_8UC1);
  result = minus_(dilatacao(image, mascara), erosao(image, mascara));

  return result;
}


Mat Processamento::abertura( const Mat& image, float mascara[100] )
{
  Mat result(image.rows, image.cols, CV_8UC1);
  result = dilatacao(erosao(image, mascara) , mascara);

  return result;
}


Mat Processamento::fechamento( const Mat& image, float mascara[100] )
{
  Mat result(image.rows, image.cols, CV_8UC1);
  result = erosao(dilatacao( image, mascara) , mascara);

  return result;
}


Mat Processamento::isolar_canais( const Mat& image, int cor)
{
  Mat result(image.rows, image.cols, CV_8UC3, Scalar(0,0,0));
  Vec3b rgb;

  for ( int i=0; i<image.cols; i++ )
  {
    for ( int j=0; j<image.rows; j++ )
    {
      rgb = image.at<Vec3b> ( j, i );
      result.at<Vec3b> ( j, i ) [cor] = rgb[cor];
    }
  }
  return result;
}

Mat Processamento::incrementar( const Mat& image, int cor, uchar incremento)
{
  Mat result(image.rows, image.cols, CV_8UC3, Scalar(0,0,0));
  Vec3b rgb;
  int resultado;

  for ( int i=0; i<image.cols; i++ )
  {
    for ( int j=0; j<image.rows; j++ )
    {
      rgb = image.at<Vec3b> ( j, i );

      for(int k=0; k<3; k++)
      {
    if(k == cor)
    {
      resultado = rgb[k] + ( (incremento*rgb[k]) /100 );

      if(resultado >= 255)
        resultado = 255;
      if(resultado <= 0)
        resultado = 0;
    }
    if(k != cor)
      resultado = abs(rgb[k]);

    result.at<Vec3b> ( j, i ) [k] = resultado;
      }
    }
  }
  return result;
}


Mat Processamento::zoom_in(const Mat& image)
{
  Mat result((image.rows * 2), (image.cols * 2), CV_8UC3, Scalar(0,0,0));
  Vec3b rgb;
  int cont_l =0;
  int cont_c =0;

  for ( int i=0; i<image.cols; i++)
  {
    for ( int j=0; j<image.rows; j++ )
    {
      rgb = image.at<Vec3b>( j, i );

      for ( int x=cont_c; x<=cont_c+1; x++ )
      {
    for ( int y=cont_l; y<=cont_l+1; y++ )
    {
      for(int k=0; k<=2; k++)
      {
        result.at<Vec3b>( y+j, x+i )[k] = rgb[k];
      }
    }
      }cont_l++;
    }cont_c++;
    cont_l = 0;
  }
  return result;
}


Mat Processamento::zoom_out(const Mat& image)
{
  Mat result((image.rows / 2), (image.cols / 2), CV_8UC3, Scalar(0,0,0));
  Vec3b rgb;

  for ( int i=0; i<image.cols; i++)
  {
    for ( int j=0; j<image.rows; j++ )
    {
      rgb[0] = (image.at<Vec3b>( j, i )[0] + image.at<Vec3b>( j+1, i )[0] + image.at<Vec3b>( j, i+1 )[0] + image.at<Vec3b>( j+1, i+1 )[0])/4;
      rgb[1] = (image.at<Vec3b>( j, i )[1] + image.at<Vec3b>( j+1, i )[1] + image.at<Vec3b>( j, i+1 )[1] + image.at<Vec3b>( j+1, i+1 )[1])/4;
      rgb[2] = (image.at<Vec3b>( j, i )[2] + image.at<Vec3b>( j+1, i )[2] + image.at<Vec3b>( j, i+1 )[2] + image.at<Vec3b>( j+1, i+1 )[2])/4;

      for(int k=0; k<=2; k++)
      {
    if(rgb[k] >= 255)
      rgb[k] = 255;

    result.at<Vec3b>(j/2, i/2 )[k] = rgb[k];
      }

    }
  }
  return result;
}


/*
 * Ver quantos pixes vermelho tem valor 0 , 1, 2 ... até 255 e plotar um grafico
 * fazer com o verde e azul também.
 */
void Processamento::histograma(const Mat& image)
{
  int vetor[3] [256] = {0};

  for ( int i=0; i<image.cols; i++)
  {
    for ( int j=0; j<image.rows; j++ )
    {

      for( int k=0; k<=2; k++)
      {
    for(int x=0; x<=255; x++)
    {
      if(image.at<Vec3b>( j, i )[k] == x)
      vetor[k][x] = vetor[k][x] +1;
    }
      }

    }
  }

  Mat grafico(500, 256, CV_32FC3);
  for(int x=0; x<256; x++)
  {
    int red = vetor[0][x];
    circle(grafico, Point(x,grafico.rows-1-red/100), 1, Scalar(0,0,255));//(onde vai desenha, centro, raio , cor)
    int green = vetor[1][x];
    circle(grafico, Point(x,grafico.rows-1-green/100), 1, Scalar(0,255,0));
    int blue = vetor[2][x];
    circle(grafico, Point(x,grafico.rows-1-blue/100), 1, Scalar(255,0,0));
  }
  imshow("grafico",grafico);
  Mat result(image.rows, image.cols, CV_8UC3, Scalar(0,0,0));
}


/*
 * Mostra info da posição e valor do pixel ao clicar nele
 */
void Processamento::info_pixel(Mat& image, String nomeTela)
{
  //setMouseCallback(nomeTela, on_mouse, &image);
}


void Processamento::on_mouse( int e, int x, int y, int d, void *ptr )
{
  Mat* rgb = (Mat*) ptr;
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "RGB:" << endl;
  printf("%d, %d, %d\n",
  (int)(*rgb).at<Vec3b>(y, x)[0],
  (int)(*rgb).at<Vec3b>(y, x)[1],
  (int)(*rgb).at<Vec3b>(y, x)[2]);
}
