//CHANGE HEADER FILE att too!!!!! header file covariance.h and discriminant.h
// functions in covariance.h need to be modified
// get inverseof to return separately


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "inverse.h"
#include "covariance.h"
#include "discriminant.h"
#define att 9

int main()
   {
   
   FILE *fp1,*fp2,*fp3,*fp4,*fp5;
   int n1,n2,i,j,n3,n4;
   double p1,p2;
   float **x1,**x2,**c1,**c2,g1,g2,*x,**mean1,**mean2;
   //printf("enter the feature values\n");


   int confuse[2][2]={{0, 0},{0, 0}};
   // for(i=0;i<att;i++)
   //  scanf("%f",&x[i]);
   fp1 = fopen("data_train1.txt","r");
   fp2 = fopen("data_train2.txt","r");
   fp3 = fopen("data_test1.txt","r");
   fp4 = fopen("data_test2.txt","r");
   fp5 = fopen("confusion_matrix1.txt","w+");
   fscanf(fp1,"%d",&n1);
   fscanf(fp2,"%d",&n2);
   fscanf(fp3,"%d",&n3);
   fscanf(fp4,"%d",&n4);
   
   int num = n1 + n2;
   p1 = (double)n1/num;
   p2 = (double)n2/num;
   x1 = (float**)malloc(n1*sizeof(float*));
   x2 = (float**)malloc(n2*sizeof(float*));
   c1 = (float**)malloc(n1*sizeof(float*));
   c2 = (float**)malloc(n2*sizeof(float*));
   for(i=0;i<n1;i++)
     {
   x1[i] = (float*)malloc(att*sizeof(float));
   c1[i] = (float*)malloc(att*sizeof(float));
     }
   for(i=0;i<n2;i++)
      {
   x2[i] = (float*)malloc(att*sizeof(float));
   c2[i] = (float*)malloc(att*sizeof(float));
      }

   for(i=0;i<n1;i++)
      {
   for(j=0;j<att;j++)
      {
   fscanf(fp1,"%f",&x1[i][j]);
   c1[i][j] = x1[i][j];
      } 
      }
    

   for(i=0;i<n2;i++)
      {
   for(j=0;j<att;j++)
      {
   fscanf(fp2,"%f",&x2[i][j]);
   c2[i][j] = x2[i][j];
      }
      }
   float **inverse = calculatemean(c1,c2,n1,n2);
    printf("Inverse of covariance matrix\n");
    for(i=0;i<att;i++)
       {
    for(j=0;j<att;j++)
       printf("%lf ",inverse[i][j]);
       printf("\n");
       }
   
    
    mean1 = getmean(x1,n1);
    mean2 = getmean(x2,n2);
    for(i=0;i<n3;i++)
        {
     x = (float*)malloc(att*sizeof(float));
     for(j=0;j<att;j++)
        {
     fscanf(fp3,"%f",&x[j]);
         } 
    g1 = getdiscriminant(x,inverse,mean1);
    g2 = getdiscriminant(x,inverse,mean2);
   // printf("\n%lf %lf",p1,p2);
    g1 = g1 + log(p1);
    g2 = g2 + log(p2);
   // printf("\ng1=%f g2=%f",g1,g2);
    if(g1>g2)   confuse[0][0]++;
    else        confuse[1][0]++;
         free(x);
         }
      fclose(fp3);
     for(i=0;i<n4;i++)
        {
     x = (float*)malloc(att*sizeof(float));
     for(j=0;j<att;j++)
        {
     fscanf(fp4,"%f",&x[j]);
         } 
    g1 = getdiscriminant(x,inverse,mean1);
    g2 = getdiscriminant(x,inverse,mean2);
   // printf("\n%lf %lf",p1,p2);
    g1 = g1 + log(p1);
    g2 = g2 + log(p2);
  //  printf("\ng1=%f g2=%f",g1,g2);
    if(g2>g1)   confuse[0][1]++;
    else        confuse[1][1]++;
    free(x);
          }
      fclose(fp4);  
      fprintf(fp5,"%d %d\n%d %d",confuse[0][0],confuse[0][1],confuse[1][0],confuse[1][1]);
      fclose(fp5);
    for(i=0;i<att;i++)
      {
      free(x1[i]);
      free(x2[i]);
      free(c1[i]);
      free(c2[i]);
      }
      free(x1);
      free(x2);
      free(c1);
      free(c2);
      fclose(fp1);
      fclose(fp2);
        
      return 0;
       }
   
