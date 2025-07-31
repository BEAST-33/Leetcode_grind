#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;
int count = 0;

vector<int> arrival ;
vector<int> departure ;
class Solution {
public:
    

    int dfs2ecCheck(int node, int p ,vector<vector<int> > & adj,vector<int>& visited ) {
        visited[node] =  1;
        arrival[node]= count++;
        int dbe = INT_MAX;
        for ( auto v : adj[node]){
            if ( v == p)continue;
            if ( !visited[v]){
                dbe = min(dbe , dfs2ecCheck(v,node,adj,visited));
            }
            else{
                dbe = min(dbe , arrival[v]);
            }
            if ( dbe > arrival[node]) ;//edgefound = true;
        }

         
         departure[node]= count++;
         return dbe;
    }
    int count = 0;
    
};


int main() {

    struct TestCase {
        vector<vector<int>> adj;
        int V;
        int root;
        string description;
    };

    vector<TestCase> tests = {
        // Triangle (cycle), no bridges
        { { {}, {2,3}, {1,3}, {1,2} }, 3, 1, "Triangle (cycle)" },
        // Line (tree), all edges are bridges
        { { {}, {2}, {1,3}, {2} }, 3, 1, "Line (tree)" },
        // Disconnected: 1-2, 3-4
        { { {}, {2}, {1}, {4}, {3} }, 4, 1, "Disconnected graph" },
        // Star, all edges are bridges
        { { {}, {2,3,4}, {1}, {1}, {1} }, 4, 1, "Star graph" },
        // Cycle with a tail (1-2-3-4-2)
        { { {}, {2}, {1,3,4}, {2,4}, {2,3} }, 4, 1, "Cycle with a tail" }
    };

    Solution obj;
    for (size_t i = 0; i < tests.size(); ++i) {
        int V = tests[i].V;
        vector<vector<int>> adj = tests[i].adj;
        int root = tests[i].root;
        vector<int> visited(V+1, 0);
        arrival.assign(V+1, 0);
        departure.assign(V+1, 0);
        
        int res = obj.dfs2ecCheck(root, -1, adj, visited);
        cout << "Test " << (i+1) << ": " << tests[i].description << endl;
        cout << "Result: " << res << endl;
        cout << "Arrival: ";
        for (int j = 1; j <= V; ++j) cout << arrival[j] << ' ';
        cout << "\nDeparture: ";
        for (int j = 1; j <= V; ++j) cout << departure[j] << ' ';
        cout << "\n---\n";
    }
    return 0;
}