#include<iostream>
#include<climits>

using namespace std;

int matrixChainMultiplication( int p[] , int n );

int main()
{
    int arr[] = {1 , 3 , 4 , 8 , 9};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = matrixChainMultiplication(arr , size);

    cout << endl << "Minimum number of multiplication : " << result << endl;
}

int matrixChainMultiplication( int p[] , int n ){

    int m[n][n];
    int i , j , k , l , num = 0;

    for( i=1; i<n; i++ ){

        m[i][i] = 0;
    }

    for( l=2; l<n; l++ ){

        for( i=1; i<=n-l+1; i++ ){

            j = i+l-1;
            m[i][j] = INT_MAX; // maximum value for an object type int

            for( k=i; k<j; k++ ){

                num = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if( num < m[i][j] ){

                    m[i][j] = num;
                }
            }
        }
    }

    return m[1][n-1];
}
