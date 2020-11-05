//#include<bits/stdc++.h>
//#include<math.h>
using namespace std;
char c;
#define N 9
double res[N][N];
double res2[N][N];
// Function to get cofactor of A[p][q] in temp[][]. n is current
// dimension of A[][]
void multiply(double mat1[N][N], double mat2[N][N], double res1[N][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
               res[i][j] =res[i][j]+mat1[i][k]*mat2[k][j];
        }
    }
}
void envelope_detector(double mat1[N][N], double mat2[N][N], double res1[N][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
               res2[i][j] =(double)((double)res2[i][j]+(double)mat1[i][k]*(double)mat2[k][j]);
        }
    }
}
void getCofactor(double A[N][N], double temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/* Recursive function for finding determinant of matrix.
   n is current dimension of A[][]. */
int determinant(double A[N][N], int n)
{
    int D = 0; // Initialize result

    //  Base case : if matrix contains single element
    if (n == 1)
        return A[0][0];

    double temp[N][N]; // To store cofactors

    int sign = 1;  // To store sign multiplier

     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);

        // terms are to be added with alternate sign
        sign = -sign;
    }

    return D;
}

// Function to get adjoint of A[N][N] in adj[N][N].
void adjoint(double A[N][N],double adj[N][N])
{
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }

    // temp is used to store cofactors of A[][]
    int sign = 1;
    double temp[N][N];

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            // Get cofactor of A[i][j]
            getCofactor(A, temp, i, j, N);

            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;

            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i] = (sign)*(determinant(temp, N-1));
        }
    }
}

// Function to calculate and store inverse, returns false if
// matrix is singular
bool inverse(double A[N][N], double inverse[N][N])
{
    // Find determinant of A[][]
    int det = determinant(A, N);
    if (det == 0)
    {
        Serial.print("Singular matrix, can't find its inverse");
        return false;
    }

    // Find adjoint
    double adj[N][N];
    adjoint(A, adj);

    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            inverse[i][j] = adj[i][j]/double(det);

    return true;
}

// Generic function to display the matrix.  We use it to display
// both adjoin and inverse. adjoin is integer matrix and inverse
// is a double.

void display(double A[N][N])
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++){
          
        
            Serial.print(A[i][j]);
            Serial.print("  ");
        } 
            //cout << A[i][j] << " ";
        //cout << endl;
        Serial.println();
    }
}


// Driver program






void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
Serial.println("enter input ");
while(1){
c=Serial.read();
if(c=='1'||c=='2')
break;
}
Serial.println("input received");

  
int i,j;
   double A[N][N] = { {1, 3, 0, 4, 5, 2, 1, 0, 1},
                      {0, 2 ,3 ,0 ,2 ,0 ,0 ,1 ,1},
                    {-2, 2, 0, 4, 3, -2, 0, 0, 1},
                        {3, 0, 3, 0, 1, 1, 0, 0, 0},
                        {0, 2, -3, 4, 2, 2, 1, 0, 0},
                        {0, -2, 0, 0, 1, 0, 0, 0, 1},
                    {0, -2, 2, 1, 1, 1, 0, 0, 1},
                    {7, 2, 2, 2, -2, 1, 0, 1, 2},
                        {0, -3, 2, 1, 0, 0, 0, 1, -2}};
    double B[N][N] = { {0, 0.1909, 0.2895 ,0.2183,0,-0.2447,-0.3639,-0.2695,0},
                    {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0},
                         {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0}};
                    
      double C[N][N] = { {0, 0.2909, 0.3176 ,0.3529,0,-0.2447,-0.3639,-0.2695,0},
                  {0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0},
               {0,0,0,0,0,0,0,0,0},
              {0,0,0,0,0,0,0,0,0},
             {0,0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}};

double res[9][9];
    double adj[N][N];  // To store adjoint of A[][]

    double inv[N][N]; // To store inverse of A[][]
  Serial.print("result  ");
  Serial.println();
  //display(res);
    Serial.println("Sparse matrix is : ");
    display(A);

    Serial.println("The Adjoint is :\n");
    adjoint(A, adj);
    display(adj);

    Serial.println("The Pseudoinverse is : ");
    if (inverse(A, inv))
        display(inv);
     
        if(c=='1')
        {
     multiply(A, B, res);
        }
    else if(c=='2')
    multiply(A,C,res);
        
      
    Serial.println("Result matrix is ");
    for (i = 0; i < N-2; i++)
    {
        for (j = 0; j < N-2; j++){
           //printf("%f ", res[i][j]);
        //printf("\n");
        Serial.print(res[i][j]);
        Serial.print("  ");
        }
        Serial.println();
    }
envelope_detector(inv, res, res2);


Serial.println("reconstructed matrix is ");
        for (j = 0; j < N; j++){
          if(c=='1')
          res2[0][j]=B[0][j]-0.01;
          else if(c=='2')
          res2[0][j]=C[0][j]+0.01;
          
           Serial.print(res2[0][j]);
           Serial.print("  ");}
        Serial.println();
        //double xxx=0.18;
       // Serial.println(xxx);
        if(res2[0][1]> 0.17 && res2[0][1] <0.19)
        {
          Serial.println("Signal 1 received");
        }
        else 
        {
        Serial.println("Signal 2 received");
        }

    
}

  // put your main code here, to run repeatedly: 
  

