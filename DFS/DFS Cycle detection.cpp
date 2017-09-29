#include<iostream>

using namespace std;

/*

sample :
n = 5 , e = 10

0 1
0 3
1 2
1 3
3 1
3 4
4 1
2 4
2 3
2 4

Adjacency Matrix :

0 1 0 1 0
0 0 1 1 0
0 0 0 1 1
0 1 0 0 1
0 1 0 0 0

*/

const int size = 999;
int adjacentMatrix[size][size] , n , e;
int color[size] , d[size] , p[size] , f[size] , time;
bool detection = false;

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

    cout << endl;

    DFS();

    if( detection ){

        cout << endl << "Cycle detected. " << endl;
    }else{

        cout << endl << "There are no cycles. " << endl;
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

    color[u] = 1;
    d[u] = ++time;

    for( int v=0; v<n; v++ ){

        if( adjacentMatrix[u][v] ){

            if( color[v]==0 ){

                DFS_visit(v);
            }else if( color[v]==1 ){

                cout << u << " -> " << v << " : Back Edge." << endl;
                detection = true;
            }
        }
    }

    color[u] = 2;
    f[u] = ++time;
}
