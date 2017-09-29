#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int arr[100] , i , n , beg , ending , mid , element;

    cout << "Enter the size of the array : ";
    cin >> n;

    cout << endl << "Enter the values : ";
    for( i=0; i<n; i++ ){

        cin >> arr[i];
    }

    cout << endl << "Enter the element that needs to be find : ";
    cin >> element;

    beg = 0;
    ending = n-1;

    while( beg<=ending ){

        mid = (beg+ending)/2;

        if( arr[mid] == element ){

            cout << endl << "Data found at the position  : " << mid+1 << endl;
            return 0;
        }

        if( arr[mid] > element ){

            ending = mid - 1;
        }else{

            beg = mid + 1;
        }
    }

    cout << endl << "Data not found." << endl;
    getch();
}
