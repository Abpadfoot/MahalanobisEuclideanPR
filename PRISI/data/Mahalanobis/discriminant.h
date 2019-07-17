#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define att 4
#ifndef __discriminant__h
  #define __discriminant__h


  float getdiscriminant(float *x,float **inverse,float **mean)
        {
     float **difference =            (float**) malloc(1*sizeof(float*)); //1*att
     float **difference_transpose =   (float**) malloc(att*sizeof(float*)); //att*1
     float **first                =   (float**) malloc(att*sizeof(float*)); //att*1
     int i,j;
     float g = 0.0;
     difference[0]                =(float*)malloc(att*sizeof(float));  

     for(i=0;i<att;i++)
     {
     difference_transpose[i]          = (float*)malloc(1*sizeof(float));
     first[i]                         = (float*)malloc(1*sizeof(float));
     }

     for(i=0;i<att;i++)
          {
        
        difference[0][i]           = x[i] - mean[0][i];
        difference_transpose[i][0] = difference[0][i];
          }

     for(i=0;i<att;i++)
        first[i][0] =0.0;
           //multiply by covariance inverse
     for(i=0;i<att;i++)
      {
     for(j=0;j<att;j++)
      {
        first[i][0] += inverse[i][j]*difference_transpose[j][0];
      }}
     for(i=0;i<att;i++)
        {
      g = g + difference[0][i]*first[i][0];
         }
      return -g/2;
       }//end
#endif
