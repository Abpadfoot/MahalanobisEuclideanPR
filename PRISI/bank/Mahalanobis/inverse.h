#include<math.h>
#include<stdio.h>
#include<malloc.h>

#ifndef __inverse__h
  #define __inverse__h
 
float determinant(float **matrix,int n)
          {
   int i,j,k;
   float ratio,det;
       for(i = 0; i < n; i++){


        for(j = 0; j < n; j++){


            if(j>i){


                ratio = matrix[j][i]/matrix[i][i];


                for(k = 0; k < n; k++){


                    matrix[j][k] -= ratio * matrix[i][k];


                }

            }
        }


    }


    det = 1; //storage for determinant


    for(i = 0; i < n; i++)


        det *= matrix[i][i];
          return det;
       }



float** inverseof(float **A,int n)
{
     int i,j,k;
     float **I,temp;
   I=(float **)malloc(n*sizeof(float *));	
      for(i=0;i<n;i++)
         I[i]=(float *)malloc(n*sizeof(float));
        for(i=0;i<n;i++)		
        for(j=0;j<n;j++)
            if(i==j) I[i][j] = 1;
         else I[i][j] = 0;
        for(k=0;k<n;k++)		
           {
           temp = A[k][k];
               for(j=0;j<n;j++)
              {
                A[k][j]/=temp;
                I[k][j]/=temp;
               }
               for(i=0;i<n;i++)
                {
               temp = A[i][k];
                for(j=0;j<n;j++)
                 {
                   if(i==k)
                        break;
                  A[i][j]-=A[k][j]*temp;
                  I[i][j]-=I[k][j]*temp;
                  }}}
           /*  for(i=0;i<matsize;i++)
               {
             for(j=0;j<matsize;j++)
              {
                printf("%f ",I[i][j]);
              } 
                printf("\n");
          
             }*/
             return I;
 }
#endif
