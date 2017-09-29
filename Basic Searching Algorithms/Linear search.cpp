#include<iostream>

using namespace std;

int main()
{
    int arr[100] , i , n , element;

    cout << "Enter the size of the array : ";
    cin >> n;

    cout << endl << "Enter the values : ";
    for( i=0; i<n; i++ ){

        cin >> arr[i];
    }

    cout << endl << "Enter the element : ";
    cin >> element;

    for( i=0; i<n; i++ ){

        if( arr[i] == element ){

            cout << "Element found at the position : " << i+1 << endl;
            return 0;
        }
    }

    cout << endl << "Element not found." << endl;
}
