#include<iostream>
#include<list>

using namespace std;

/*

n = 15 , e = 21

1 2
1 4
1 5
1 15
2 3
3 4
4 6
5 6
5 7
5 14
6 8
7 8
7 10
8 9
9 10
9 12
10 11
11 13
12 13
13 14
14 15

s = 2

Adjacency Matrix :

0 1 0 1 1 0 0 0 0 0 0 0 0 0 1
0 0 1 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 1 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

*/

const int size = 999;
int adjacentMatrix[size][size] , n , e , s;
int color[size] , d[size] , p[size];
list <int> queue;

void BFS( int s , int n );

int main()
{
    for( int i=1; i<=size; i++ ){

        for( int j=1; j<=size; j++ ){

            adjacentMatrix[i][j] = 0;
        }
    }

    cout << endl << "Enter the number of nodes and edges : ";
    cin >> n >> e;

    if( e > n*(n-1) ){

        cout << endl << "Invalid edges...!!! " << endl;
        return 0;
    }

    cout << endl << "Enter the nodes(u , v) which are connected : " << endl << endl;
    for( int i=1; i<=e; i++ ){

        int u , v;
        cin >> u >> v;
        adjacentMatrix[u][v] = 1;
    }

    cout << endl << "Adjacency Matrix : " << endl << endl;
    for( int i=1; i<=n; i++ ){

        for( int j=1; j<=n; j++ ){

            cout << adjacentMatrix[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << "Enter the source : ";
    cin >> s;

    cout << endl << "BFS visiting order : " << endl << endl;

    BFS( s , n );
}

void BFS( int s , int n ){

    for( int i=1; i<=n; i++ ){

        d[i] = 0;
        p[i] = -1;
        color[i] = 0;
    }

    queue.push_back(s);

    while( !queue.empty() ){

        int u = queue.front();
        cout << u << " -> ";
        queue.pop_front();

        for( int v=1; v<=n; v++ ){

            if( adjacentMatrix[u][v] == 1 && color[v] == 0 ){

                color[v] = 1;
                d[v] = d[u] + 1;
                p[v] = u;
                queue.push_back(v);
            }
        }

        color[u] = 2;
    }

    cout << endl;
}
