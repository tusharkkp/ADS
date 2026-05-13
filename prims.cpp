#include <iostream>
using namespace std;

#define MAX 10 // max vertices 
#define INF 999 // for infinity used when no edge existss

class Graph {
    int cost[MAX][MAX]; // adjency matrix stores edge weights
    int visited[MAX]; // tracks visited vertices 
    // 0 - not visited
    // 1 = visited 
    
    int n; // stores vertices (<10)

public:

    void input() {
        cout << "Enter number of vertices: ";
        cin >> n; // <10

        cout << "Enter adjacency matrix:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                cin >> cost[i][j];

                if (i != j && cost[i][j] == 0)
                    cost[i][j] = INF;
            }
        }
    }

    void prims() {

        int mincost = 0; // stores minimum possible mst cost
        int ne = 1; // counts no of edges (v-1)

        for (int i = 0; i < n; i++){
            visited[i] = 0;  // visited vertex array
    	}

        visited[0] = 1;

        cout << "\nEdges in MST:\n";

        while (ne < n) { // v-1 < v

            int min = INF; // stores min edge (initally Infinity)
            int a = -1, b = -1; // EDGE (A to B)

            for (int i = 0; i < n; i++) { // traverse vertices

                if (visited[i]) { // proceed if visited 

                    for (int j = 0; j < n; j++) { // neighbouring vertices

                        if (!visited[j] &&  //not visited && cost is lower than Min
                            cost[i][j] < min) {

                            min = cost[i][j]; // update min
                            a = i;
                            b = j; // stores selected edge (A to B)
                        }
                    }
                }
            }

            if (min == INF) { // if min == infinity then dis
                cout << "Graph is disconnected!";
                return;
            }

            cout << a << " -> " << b
                 << " = " << min << endl; // for selected edge a to b min weight 

            mincost += min; // in the final mincost of mst add min edge weight of selected edge a to b
            visited[b] = 1; // marks 
            ne++;
        }

        cout << "Minimum cost = "  // prints final cost 
             << mincost << endl;
    }
};

int main() {

    Graph g;

    g.input();
    g.prims();

    return 0;
}