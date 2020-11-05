#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int N=9;
float adj[9][9];
float **inv;

float **transpose(float num[9][9], float fac[9][9], float r);

void multiply(float mat1[9], float mat2[9][9], float res1[9])
{
    float *res;
    int  j, k;
            for (j = 0; j < 9; j++)
        {
            res[j] = 0;
            for (k = 0; k < 9; k++){
                *(res+j) += *(mat1+j)  *  (*(*(mat2+k)+j));
        }
        }

    }
void multiply2(float mat1[9], float mat2[9][9], float res)
{
    float *res;
    int  j, k;
            for (j = 0; j < 9; j++)
        {
            res[j] = 0;
            for (k = 0; k < 9; k++)
                *(res+j) += mat1[k]*mat2[j][k];
        }

    }

    float determinant(float a[9][9], float k)
{
  float s = 1, det = 0, b[9][9];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }

    return (det);
}

    float **cofactor(float num[9][9], float f)
{
 float b[9][9], fac[9][9]; float **cofac=0;
 int p, q, m, n, i, j;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  cofac = transpose(num, fac, f);
return cofac;
}
float **transpose(float num[9][9], float fac[9][9], float r)
{
  int i, j;
  float b[9][9], inverse[9][9], d; float **trans;

  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = determinant(num, r);
  for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }
   printf("\n\n\nThe inverse of sparse matrix is : \n");

   for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
         printf("\t%f", inverse[i][j]);
        }
    printf("\n");
     }
      for (i = 0;i < 9; i++)
     for (j = 0;j < 9; j++)
*(*(trans+i)+j) = inverse[i][j];

return trans;
}

    float **inverse(float n, float A[9][9])
    {

      float **a; float k, d;
  int i, j;

   d = determinant(A, n);
  if (d == 0)
   printf("\nInverse of Entered Matrix is not possible\n");
  else
   a = cofactor(A, n);

   return a;
}


/*
void getCofactor(float A[9][9], float temp[9][9], int p, int q, int n)
{
    int i = 0, j = 0;

        for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];

                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

float determinant(float A[9][9], int n)
{
    int D = 0;
    if (n == 1)
        return A[0][0];

    float temp[9][9];

    int sign = 1;


    for (int f = 0; f < n; f++)
    {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);

        sign = -sign;
    }

    return D;
}


void adjoint(float A[9][9],float adj[9][9])
{
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }


    int sign = 1; float temp[9][9];

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {

            getCofactor(A, temp, i, j, N);

            sign = ((i+j)%2==0)? 1: -1;
 adj[j][i] = (sign)*(determinant(temp, N-1));
        }
    }
}

void inverse(float A[9][9], float inverse[9][9])
{

    int det = determinant(A, 9);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";

    }


    float adj[9][9];
    adjoint(A, adj);


    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            inverse[i][j] = adj[i][j]/float(det);
            printf("%f ",inverse[i][j]);}
            printf("\n");}


}*/
int main(){
float f=50;
float w=2*3.14*f;
float T=0.02;
int a=1;
int i=0;
float s[9];  float *res;  float *res2;
printf("the sampled signal \n");
for(float t=0;t<=0.02;t=t+0.0025){
    s[i]=a*sin(w*t);
    printf("%f ",s[i]);
    i++;
    }
printf("\n");
float sparse[9][9]={
    64,   -16,     0,   -16,     0,     0,     0 ,    0,     0,
   -16,   64,   -16,     0,   -16,     0,     0,     0,     0,
     0,   -16,    64,     0,     0,   -16,     0,     0,     0,
   -16,     0,     0,    64,   -16,     0,   -16,     0,     0,
     0,   -16,     0,   -16,    64,   -16,     0,   -16,     0,
     0,     0,   -16,     0,  -16,    64,     0,     0,   -16,
     0,     0,     0,   -16,     0,     0,    64,   -16,     0,
     0,     0,     0,     0,   -16,     0,   -16,    64,   -16,
     0,     0,     0,     0,     0,   -16,     0,   -16,    64} ;



res = multiply(s,sparse);
printf("the encoded signal is: \n");
for(int i=0;i<9;i++){
     printf("%f  ",res[i]);
    }
printf("\n");


inv=inverse(9.0,sparse);
//inverse(sparse,inv);
/*for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        printf("%f",inv[i][j]);
    }

    printf("\n");
}
printf("\n");*/
res2 = multiply2(res, inv);
printf("the reconstructed signal is : \n");
for(int i=0;i<9;i++){
    printf("%f  ",res2[i]);
    }


}
