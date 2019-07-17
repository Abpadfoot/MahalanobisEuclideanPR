#include<math.h>
#include<stdio.h>
#include<malloc.h>
#include "inverse.h"
#define att 167
#ifndef __covariance__h
  #define __covariance__h
   


   float** covariance(float **x1,float **x2,float **mean1,float **mean2,int n1,int n2)
                          {
   int i,j,m,n;
   float **sum1,**temp1,**temptranspose1,**covariance1, **sumtranspose1,**copy1, **I;
   sum1 =           (float**)malloc(att*sizeof(float*));
   covariance1 =    (float**)malloc(att*sizeof(float*));
   copy1        =   (float**)malloc(att*sizeof(float*));
   temptranspose1 = (float**)malloc(att*sizeof(float*));
   sumtranspose1 =  (float**)malloc(att*sizeof(float*));
   temp1 =          (float**)malloc(1*sizeof(float*));
   for(i=0;i<att;i++)
     {
   sum1[i]          = (float*)malloc(att*sizeof(float));
   covariance1[i]   = (float*)malloc(att*sizeof(float));
   copy1[i]   = (float*)malloc(att*sizeof(float));
   sumtranspose1[i]  = (float*)malloc(1*sizeof(float));
   temptranspose1[i] =(float*)malloc(1*sizeof(float));
     }
   temp1[0]            =(float*)malloc(att*sizeof(float));  
  
    for(m=0;m<att;m++)
             {
    for(n=0;n<att;n++)
             {
    covariance1[m][n]= 0.0;
                        
            }}
               
    for(i=0;i<n1;i++)
             {
    for(j=0;j<att;j++)
              {
    temp1[0][j] = (x1[i][j]-mean1[0][j]); //change
    temptranspose1[j][0]=temp1[0][j];
              }  
                 
     for(m=0;m<att;m++)
            {
     for(n=0;n<att;n++)
              {
     sum1[m][n] = (temptranspose1[m][0]*temp1[0][n]);
               }   }
          
                   
      for(m=0;m<att;m++)
               {
       for(n=0;n<att;n++)
                       {
        covariance1[m][n]= covariance1[m][n] + sum1[m][n];
                       }}
                  
                       }
                      
        for(m=0;m<att;m++)
                      {
        for(n=0;n<att;n++)
                 {
        covariance1[m][n]= covariance1[m][n]/n1;//change
        copy1[m][n]      = covariance1[m][n];
                    }}
        printf("\ncovariance matrix\n");
      /* for(m=0;m<att;m++)
                {
        for(n=0;n<att;n++)
                 {
          printf("%f ",covariance1[m][n]);
                 }
              printf("\n");
                  }*/
         float det1 = determinant(copy1,att);
        // printf("%f\n",det1);
         if(det1!=0)
         I = inverseof(covariance1,att);
         return I;
                 }//function



   

                
   
   float** calculatemean(float **x1,float **x2,int n1,int n2)
                          {

    float **mean1,**mean2,**sum1,**sum2;
    int i,j;
    mean1 = (float**)malloc(1*sizeof(float*));
    mean2 = (float**)malloc(1*sizeof(float*));
    sum1  = (float**)malloc(1*sizeof(float*));
    sum2  = (float**)malloc(1*sizeof(float*));  
    for(i=0;i<1;i++)
      {
    mean1[i] = (float*)malloc(att*sizeof(float));
    mean2[i] = (float*)malloc(att*sizeof(float));
    sum1[i]  = (float*)malloc(att*sizeof(float));
    sum2[i]  = (float*)malloc(att*sizeof(float));
      }

    for(i=0;i<att;i++)
      {
    sum1[0][i]=0.0;
    sum2[0][i]=0.0;
                       
      }
                                      
    for(i=0;i<(n1);i++)
      {
    for(j=0;j<att;j++)
      {
           
    sum1[0][j]=sum1[0][j] + x1[i][j];
      }
      }
    for(j=0;j<att;j++)
      {
    mean1[0][j]= sum1[0][j]/(n1);
      }
                               
                                      
    for(i=0;i<(n2);i++)
      {
    for(j=0;j<att;j++)
      {
                             
    sum2[0][j]=sum2[0][j] + x2[i][j];
       }
       }
    for(j=0;j<att;j++)
       {
    mean2[0][j]= sum2[0][j]/(n2);
       }
                                    
                             
    //for(j=0;j<att;j++)
    //printf(" %lf %lf\n",sum1[0][j],sum2[0][j]);
      					
    float** I= covariance(x1,x2,mean1,mean2,n1,n2);   
    return I;
                                  }



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
