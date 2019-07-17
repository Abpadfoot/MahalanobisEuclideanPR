#include<math.h>
#include<stdio.h>
#include<malloc.h>

#define att 12
#ifndef __mean__h
  #define __mean__h


 float** getmean(float **x,int n)
         {

    float **mean,**sum;
    int i,j;
    mean = (float**)malloc(1*sizeof(float*));

    sum  = (float**)malloc(1*sizeof(float*));

    for(i=0;i<1;i++)
      {
    mean[i] = (float*)malloc(att*sizeof(float));

    sum[i]  = (float*)malloc(att*sizeof(float));

      }

    for(i=0;i<att;i++)
      {
    sum[0][i]=0.0;

                       
      }
                                      
    for(i=0;i<(n);i++)
      {
    for(j=0;j<att;j++)
      {
           
    sum[0][j]=sum[0][j] + x[i][j];
      }
      }
    for(j=0;j<att;j++)
      {
    mean[0][j]= sum[0][j]/(n);
      }
                               
                                      
    return mean;
         }
#endif
   


