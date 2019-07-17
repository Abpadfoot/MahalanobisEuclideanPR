#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "mean.h"

#define att 12


  int main()
   {
    int n1,n2,n3,n4,i,variance,j,a;
    a = 0;
    float d1,d2,**x1,**mean1,**mean2,*x,**c1,**c2,**x2; 
    FILE *fp1,*fp2,*fp3,*fp4,*fp5;
    int confuse[2][2]={ {0, 0},{0, 0}};
    fp1 = fopen("data_train1.txt","r");
    fp2 = fopen("data_train2.txt","r");
    fp3 = fopen("data_test1.txt","r");
    fp4 = fopen("data_test2.txt","r");
    fp5 = fopen("confusion_matrix1.txt","w+");
    fscanf(fp1,"%d",&n1);
    fscanf(fp2,"%d",&n2);
    fscanf(fp3,"%d",&n3);
    fscanf(fp4,"%d",&n4);
   
    
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
    mean1 = getmean(x1,n1);
    mean2 = getmean(x2,n2);
    for(i=0;i<n3;i++)
      {
    x = (float*)malloc(att*sizeof(float));
    for(j=0;j<att;j++)
        {
    fscanf(fp3,"%f",&x[j]);
         } 
    for(j=0;j<att;j++)
        {
    d1 = (x[j] - mean1[0][j])*(x[j] - mean1[0][j]);
    d2 = (x[j] - mean2[0][j])*(x[j] - mean2[0][j]);
        }
    if(d1<d2)         confuse[0][0]++;
    else if(d1>d2)    confuse[1][0]++;
    else a++;
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
    for(j=0;j<att;j++)
        {
    d1 = (x[j] - mean1[0][j])*(x[j] - mean1[0][j]);
    d2 = (x[j] - mean2[0][j])*(x[j] - mean2[0][j]);
        }
    if(d2<d1)           confuse[1][1]++;
    else if(d2>d1)      confuse[0][1]++;
    else a++;
    free(x);
        }
          fclose(fp4); 
          fprintf(fp5,"%d %d\n%d %d\n%d",confuse[0][0],confuse[0][1],confuse[1][0],confuse[1][1],a);
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
 
    
    
    
