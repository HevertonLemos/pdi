#include <iostream>
#include <stdio.h>

#include "ProcessaImagem.h"
#include "Roberts_.h"
#include "Sobel_.h"
#include "Robinson_.h"
#include "BackGround.h"



int main ( int argc, char **argv )
{
   const std::string path = "../imagens/imagem.jpg";
   string imagem11 = "../imagens/imagem1.jpg";
   Mat imagem = PROCESSA_IMAGEM::openImage ( path );
   Mat imagem1 = PROCESSA_IMAGEM::openImage(imagem11);
   
  float mascaraC[9] = {
			-1,-1,-1,
			-1,8,-1,
			-1,-1,-1
		      };
  float mascaraD_E[9] = {
			  1,1,1,
			  1,0,1,
			  1,1,1
			};
  
  VideoCapture cap(0); //pegar primeira web cam
  if(!cap.isOpened())
    return -1;
  
        BackGround bg(10);
  float t, fps;
  while(true)
  {
      Mat frame;
      cap >> frame;
      t = getTickCount(); //calcula o tempo inicial
      
      //Mat resultadoNEGATIVE = PROCESSA_IMAGEM::negative ( frame ); imshow("Negative", resultadoNEGATIVE);

      
      //Mat resultadoSUM = PROCESSA_IMAGEM::sum ( frame, imagem1 ); imshow("Soma", resultadoSUM);
      
      
      //Mat resultadoSumPonderada = PROCESSA_IMAGEM::sumPonderada(frame, imagem1,30,70); imshow("Soma", resultadoSumPonderada);
      
      
//       Mat resultadoMINUS = PROCESSA_IMAGEM::minus_ ( frame, imagem1);
//       PROCESSA_IMAGEM::info_pixel(resultadoMINUS, "Subtração");
//       imshow("Subtração", resultadoMINUS);
      
      
      //Mat resultadoISOLAR_CANAIS = PROCESSA_IMAGEM::isolar_canais( frame, 2); imshow("Isolar canais", resultadoISOLAR_CANAIS);
      
      
      //Mat resultadoINCREMENTAR = PROCESSA_IMAGEM::incrementar(frame,2, 70); imshow("Incrementar", resultadoINCREMENTAR);
      
      
      //Mat resultadoZoom_in = PROCESSA_IMAGEM::zoom_in(frame); imshow("Zoom in", resultadoZoom_in);
      
      
      //Mat resultadoZoom_out = PROCESSA_IMAGEM::zoom_out(frame); imshow("Zoom out", resultadoZoom_out);
      
      
      
      
      
      //Mat resultadoGRAY = PROCESSA_IMAGEM::gray (frame ); //imshow("Tons de cinza", resultadoGRAY);
      
      
      Mat resultadoGRAY_PONDERADA = PROCESSA_IMAGEM::grayPonderada ( frame ); //imshow("Tons de cinza ponderado", resultadoGRAY_PONDERADA);
      
      
      Mat resultadoLIMIAR = PROCESSA_IMAGEM::limiarizacao ( resultadoGRAY_PONDERADA, 50); //imshow("Limiar", resultadoLIMIAR);
      
      
      //Mat resultadoDILATACAO = PROCESSA_IMAGEM::dilatacao ( resultadoLIMIAR, mascaraD_E ); imshow("Dilatação", resultadoDILATACAO);
      
      
      //Mat resultadoEROSAO = PROCESSA_IMAGEM::erosao( resultadoLIMIAR, mascaraD_E ); imshow("Erosão", resultadoEROSAO);
      
      
      //Mat resultadoCONVOLUCAO = PROCESSA_IMAGEM::convolucao(resultadoLIMIAR, mascaraC); imshow("Convolução", resultadoCONVOLUCAO);
      
      
      //Mat resultadoABERTURA = PROCESSA_IMAGEM::abertura( resultadoLIMIAR, mascaraD_E ); imshow("Abertura", resultadoABERTURA);
      
      
      //Mat resultadoFECHAMENTO = PROCESSA_IMAGEM::fechamento( resultadoLIMIAR, mascaraD_E ); imshow("fechamento", resultadoFECHAMENTO);
      
      
//      Robinson_ Rn(resultadoGRAY_PONDERADA);
//      Mat resultadoRn = Rn.getResult();
//      imshow("Robinson", resultadoRn);
//      PROCESSA_IMAGEM::info_pixel(resultadoRn, "Robinson");
      
      
//      Roberts_ Rs(resultadoGRAY_PONDERADA);
//      Mat resultadoR = Rs.getResult();
//      PROCESSA_IMAGEM::info_pixel(resultadoR, "Roberts");
//      imshow("Roberts", resultadoR);
        
        
        
//      Sobel_ S(resultadoGRAY_PONDERADA);
//      Mat resultadoS = S.getResult();
//      imshow("Sobel", resultadoS);
       
      
      
      //PROCESSA_IMAGEM::histograma(frame);
      
      

//      bg.preenche_lista(resultadoGRAY_PONDERADA);//resultadoLIMIAR);
//      bg.bg_media_lista(resultadoGRAY_PONDERADA);//resultadoLIMIAR);
//      Mat result;  
//      flip(bg.getResult(), result, 1); //colocar a imagem na posição correta(desespelhar)
//      imshow("BackGround media", result);
//       
      
//      bg.preenche_lista(resultadoGRAY_PONDERADA);
//      bg.bg_mediana_lista(resultadoGRAY_PONDERADA);
//      Mat result;
//      flip(bg.getResult(), result, 1); //colocar a imagem na posição correta(desespelhar)
//      imshow("BackGround mediana", result);
      
      
      
     bg.bg_alfa_lista(resultadoGRAY_PONDERADA);
     Mat result;
     flip(bg.getResult(), result, 1); //colocar a imagem na posição correta(desespelhar)
     imshow("BackGround alfa", result);
      

      fps = (getTickCount() - t) / getTickFrequency(); //retorna em hz/s
      fps = 1/fps; //transforma em quantidade
      //cout << fps << endl;
      if(waitKey(30) >= 0) break;
  }
    
  

  cv::waitKey ( 0 );
  return 0;
}

