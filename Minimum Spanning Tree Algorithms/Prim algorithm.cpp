#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<climits>

using namespace std;

typedef pair<int , int> iPair;
vector <iPair> adj[999];
int key[999] , parent[999];
bool visited[999];

class graph{

    int n;

    public :

        graph( int n ){

            this->n = n;
        }

        void addEdge( int u , int v , int w ){

            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }

        void primMST(){

            int src = 0 , ans = 0;
            priority_queue <iPair , vector<iPair> , greater<iPair> > pq;

            pq.push(make_pair(0 , src));
            key[src] = 0;

            while( !pq.empty() ){

                int u = pq.top().second;
                pq.pop();
                visited[u] = true;

                for( int i=0; i<adj[u].size(); i++ ){

                    int v = adj[u][i].first;
                    int w = adj[u][i].second;

                    if( !visited[v] && key[v]>w ){

                        key[v] = w;
                        pq.push(make_pair(w,v));
                        parent[v] = u;
                    }
                }
            }

            for( int i=1; i<n; i++ ){

                ans += key[i];
                cout << parent[i] << " -> " << key[i] << endl;
            }

            cout << endl << "Weight : " << ans << endl << endl;
        }
};

int main()
{
    int n = 15;

    for( int i=0; i<n; i++ ){

        key[i] = INT_MAX;
        parent[i] = -1;
    }

    graph g(n);

    g.addEdge(0 , 1 , 6);
    g.addEdge(0 , 2 , 4);
    g.addEdge(0 , 3 , 6);
    g.addEdge(0 , 8 , 10);
    g.addEdge(0 , 11 , 7);
    g.addEdge(2 , 6 , 2);
    g.addEdge(2 , 7 , 3);
    g.addEdge(3 , 6 , 1);
    g.addEdge(3 , 7 , 2);
    g.addEdge(3 , 8 , 12);
    g.addEdge(4 , 9 , 11);
    g.addEdge(4 , 14 , 9);
    g.addEdge(5 , 8 , 5);
    g.addEdge(5 , 9 , 6);
    g.addEdge(6 , 7 , 1);
    g.addEdge(7 , 11 , 11);
    g.addEdge(9 , 11 , 14);
    g.addEdge(9 , 12 , 7);
    g.addEdge(9 , 14 , 7);
    g.addEdge(10 , 11 , 10);
    g.addEdge(10 , 12 , 15);
    g.addEdge(10 , 13 , 20);
    g.addEdge(11 , 13 , 80);
    g.addEdge(12 , 13 , 31);
    g.addEdge(12 , 14 , 7);
    g.addEdge(13 , 14 , 6);

    g.primMST();
}
