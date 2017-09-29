#include<iostream>
#include<climits>

using namespace std;

/*

nodes = 5 , edges = 6

0 1 3
0 2 2
1 3 4
2 4 5
3 0 1
4 3 2

*/

const int size = 999;
int n , e , s;
int adjacent_matrix[size][size];
int d[size];
bool sptSet[size];

void createGraph();
void dijkstra();
int minDist( int dist[] , bool sptSet[] );

int main()
{
    createGraph();
}

void createGraph(){

    int u , v , w;

    cout << endl << "Enter number of the nodes and edges : ";
    cin >> n >> e;

    if( e > n*(n-1) ){

        cout << endl << "Invalid edges... !!! " << endl;
        return;
    }else{

        cout << endl << "Enter nodes(u , v) which are connected and it's cost : " << endl << endl;
        for( int i=0; i<e; i++ ){

            cin >> u >> v >> w;
            adjacent_matrix[u][v] = w;
        }

        dijkstra();
    }
}

void dijkstra(){

    cout << endl << "Enter source : ";
    cin >> s;

    for( int i=0; i<n; i++ ){

        d[i] = INT_MAX;
        sptSet[i] = false;
    }

    d[s] = 0;

    for( int i=0; i<n; i++ ){

        int u = minDist(d , sptSet);
        sptSet[u] = true;

        for( int v=0; v<n; v++ ){

            if( !sptSet[v] && adjacent_matrix[u][v] && d[u] != INT_MAX && d[u]+adjacent_matrix[u][v] < d[v] ){

                d[v] = d[u] + adjacent_matrix[u][v];
            }
        }
    }

    cout << endl << "Each vertex's distance from source : " << endl << endl;
    for( int i=0; i<n; i++ ){

        cout << i << " -> " << d[i] << endl;
    }
}

int minDist( int dist[] , bool sptSet[] ){

    int min = INT_MAX , min_index;

    for( int i=0; i<n; i++ ){

        if( sptSet[i] == false && dist[i] <= min ){

            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}
