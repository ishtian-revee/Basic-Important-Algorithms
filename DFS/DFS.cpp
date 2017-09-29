#include<iostream>

using namespace std;

/*

sample :
n = 5 , e = 10

0 3
3 0
1 3
3 1
3 4
4 3
1 4
4 1
2 4
4 2

Adjacency Matrix :

0 0 0 1 0
0 0 0 1 1
0 0 0 0 1
1 1 0 0 1
0 1 1 1 0

*/

const int size = 999;
int adjacentMatrix[size][size] , n , e;
int color[size] , d[size] , p[size] , f[size] , time;

void DFS();
void DFS_visit( int u );

int main()
{
    for( int i=0; i<size; i++ ){

        for( int j=0; j<size; j++ ){

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
    for( int i=0; i<e; i++ ){

        int u , v;
        cin >> u >> v;
        adjacentMatrix[u][v] = 1;
    }

    cout << endl << "Adjacency Matrix : " << endl << endl;
    for( int i=0; i<n; i++ ){

        for( int j=0; j<n; j++ ){

            cout << adjacentMatrix[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << "DFS visiting order : " << endl << endl;

    DFS();

    cout << endl << endl << "Node  \t  Parent" << endl << endl;
    for( int i=0; i<n; i++ ){

        cout << i << " \t " << p[i] <<endl;
    }

}

void DFS(){

    for( int i=0; i<n; i++ ){

        color[i] = 0;
        p[i] = -1;
    }

    time = 0;

    for( int i=0; i<n; i++ ){

        if( color[i]==0 ){

            DFS_visit(i);
        }
    }
}

void DFS_visit( int u ){

    cout << u << " -> ";

    color[u] = 1;
    d[u] = ++time;

    for( int v=0; v<n; v++ ){

        if( adjacentMatrix[u][v] == 1 && color[v]==0 ){

            p[v] = u;
            DFS_visit(v);
        }
    }

    color[u] = 2;
    f[u] = ++time;
}
