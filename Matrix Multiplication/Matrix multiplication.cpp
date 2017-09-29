#include<iostream>

using namespace std;

int main()
{
    int first[10][10] , second[10][10] , mult[10][10];
    int m , n , p , q , sum = 0;

    cout << endl << "Enter the number of rows and columns of matrix 1 : ";
    cin >> m >> n;

    cout << endl << "Enter the elements of matrix 1 : ";
    for( int i=0; i<m; i++ ){

        for( int j=0; j<n; j++ ){

            cin >> first[i][j];
        }
    }

    cout << endl << "Enter the number of rows and columns of matrix 2 : ";
    cin >> p >> q;

    if( n!=p ){

        cout << endl << "Incompatible dimensions." << endl;
        return 0;
    }else{

        cout << endl << "Enter the elements of matrix 2 : ";
    }

    for( int i=0; i<p; i++ ){

        for( int j=0; j<q; j++ ){

            cin >> second[i][j];
        }
    }

    for( int i=0; i<m; i++ ){

        for( int j=0; j<q; j++ ){

            for( int k=0; k<n; k++ ){

                sum = sum + ( first[i][k] * second[k][j] );
            }

            mult[i][j] = sum;
            sum = 0;
        }
    }

    cout << endl << "After multiplication : " << endl;

    for( int i=0; i<m; i++ ){

        for( int j=0; j<q; j++ ){

            cout << mult[i][j] << "\t";
        }

        cout << endl;
    }

}
