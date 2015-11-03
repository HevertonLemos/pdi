#include "Robinson_.h"

Robinson_::Robinson_(const Mat& fonte)
{
 this->fonte = fonte;
 result = executa(this->fonte);
}


Mat Robinson_::executa(const Mat& image)
{
  Mat resultado(image.rows, image.cols, CV_8UC1);

  float mascara1[9] = {
			 1, 2, 1,
			 0, 0, 0,
			-1,-2,-1
			};

  float mascara2[9] = {
			2, 1, 0,
			1, 0,-1,
			0,-1,-2
		      };
		      
  float mascara3[9] = {
			1, 0,-1,
			2, 0,-2,
			1, 0,-1
		      };

  float mascara4[9] = {
			0,-1,-2,
			1, 0,-1,
			2, 1, 0
		      };
					  
  float mascara5[9] = {
			-1,-2,-1,
			 0, 0, 0,
			 1, 2, 1
		      };
  
  float mascara6[9] = {
			-2,-1, 0,
			-1, 0, 1,
			 0, 1, 2
		      };
					  
  float mascara7[9] = {
			-1, 0,1,
			-2, 0,2,
			-1, 0,1
		      };
  
  float mascara8[9] = {
			 0, 1, 2,
			-1, 0, 1,
			-2,-1, 0
		      };

  for(int i=1; i<image.cols-1; i++)
  {
    for(int j=1; j<image.rows-1; j++)
    {
      int G[8] = {0,0,0,0,0,0,0,0};
      for(int x=-1; x<=1; x++)
      {
	for(int y=-1; y<=1; y++)
	{
	  G[0] = G[0] + (image.at<uchar>(y+j,x+i) * mascara1[(y+1)*3+(x+1)]); //(linha+1) *qtd_linha + (coluna+1)
	  G[1] = G[1] + (image.at<uchar>(y+j,x+i) * mascara2[(y+1)*3+(x+1)]); //(linha+1) *qtd_linha + (coluna+1)
	  G[2] = G[2] + (image.at<uchar>(y+j,x+i) * mascara3[(y+1)*3+(x+1)]); //(linha+1) *qtd_linha + (coluna+1
	  G[3] = G[3] + (image.at<uchar>(y+j,x+i) * mascara4[(y+1)*3+(x+1)]); //(linha+1) *qtd_linha + (coluna+1
	  G[4] = G[4] + (image.at<uchar>(y+j,x+i) * mascara5[(y+1)*3+(x+1)]); //(linha+1) *qtd_linha + (coluna+1
	  G[5] = G[5] + (image.at<uchar>(y+j,x+i) * mascara6[(y+1)*3+(x+1)]); //(linha+1) *qtd_linha + (coluna+1
	  G[6] = G[6] + (image.at<uchar>(y+j,x+i) * mascara7[(y+1)*3+(x+1)]); //(linha+1) *qtd_linha + (coluna+1
	  G[7] = G[7] + (image.at<uchar>(y+j,x+i) * mascara8[(y+1)*3+(x+1)]); //(linha+1) *qtd_linha + (coluna+1
	}
      }
      quickSort(G, 0, 7);
      if(G[7] >= 255)
	G[7] = 255;
      if(G[7] <= 0)
	G[7]=0;
      
      resultado.at<uchar>(j,i) = G[7];
    }
  }
  return resultado;
}
  
  
  
  
Mat Robinson_::getResult()
{
  return result;
}


void Robinson_::quickSort(int valor[], int esquerda, int direita)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];
 
    while(i <= j)
    {
        while(valor[i] < x && i < direita)
        {
            i++;
        }
        while(valor[j] > x && j > esquerda)
        {
            j--;
        }
        if(i <= j)
        {
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda)
    {
        quickSort(valor, esquerda, j);
    }
    if(i < direita)
    {
        quickSort(valor,  i, direita);
    }
}

