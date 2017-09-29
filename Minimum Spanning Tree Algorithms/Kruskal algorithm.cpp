#include<iostream>

using namespace std;

/*

nodes = 9 , edge = 14

1 2 4
1 8 8
2 8 12
2 3 8
8 9 6
7 8 1
7 9 5
3 9 3
3 4 6
3 6 4
6 7 3
4 6 13
4 5 9
5 6 10

minimum cost = 38

*/

int n , e , u , v , w , a , b , count = 1 , minWeight , cost = 0;
int adjacent_matrix[100][100] , weight[100][100];
int parent[100];

void createGraph();
void kruskalMST();
int find( int x );
int my_union( int i , int j );

int main()
{
    createGraph();
}

void createGraph(){

    cout << endl << "Enter number of nodes and edges : ";
    cin >> n >> e;

    if( e > n*(n-1) ){

        cout << endl << "Invalid edges...!!! " << endl;
        return;
    }else{

        cout << endl << "Enter nodes(u , v) which are connected and it's cost : " << endl << endl;
        for( int i=1; i<=e; i++ ){

            cin >> u >> v >> w;
            adjacent_matrix[u][v] = adjacent_matrix[v][u] = 1;
            weight[u][v] = weight[v][u] = w;
        }

        cout << endl << "Adjacent matrix of the graph : " << endl << endl;
        for( int i=1; i<=n; i++ ){

            for( int j=1; j<=n; j++ ){

                cout << adjacent_matrix[i][j] << " ";
            }

            cout << endl;
        }

        cout << endl << "Weight representation of the graph : " << endl << endl;
        for( int i=1; i<=n; i++ ){

            for( int j=1; j<=n; j++ ){

                cout << weight[i][j] << " ";
            }

            cout << endl;
        }

        for( int i=1; i<=n; i++ ){

            for( int j=1; j<=n; j++ ){

                if( weight[i][j] == 0 ){

                    weight[i][j] = 9999;
                }
            }
        }

        kruskalMST();
    }
}

void kruskalMST(){

    cout << endl << "The edges of the MST are : " << endl;
    cout << endl << "{" << endl;

    while( count<n ){

        minWeight = 9999;

        for( int i=1; i<=n; i++ ){

            for( int j=1; j<=n; j++ ){

                if( weight[i][j] < minWeight ){

                    minWeight = weight[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if( my_union(u,v) ){

            cout << "(" << a << " , " << b << ")" << endl;
            cost += minWeight;
            count++;
        }

        weight[a][b] = weight[b][a] = 9999;
    }

    cout << "}" << endl << endl << "Minimum cost : " << cost << endl;
}

int find( int x ){

    while( parent[x] ){

        x = parent[x];
    }

    return x;
}

int my_union( int i , int j ){

    if( i!=j ){

        parent[j] = i;
        return 1;
    }else{

        return 0;
    }
}
