#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;
class Solution {
private:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;
    
    pair<string, double> find(const string& x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            weight[x] = 1.0;
            return {x, 1.0};
        }
        
        if (parent[x] != x) {
            auto [root, w] = find(parent[x]);
            weight[x] *= w;
            parent[x] = root;
        }
        
        return {parent[x], weight[x]};
    }
    
    void unite(const string& x, const string& y, double val) {
        auto [rootX, weightX] = find(x);
        auto [rootY, weightY] = find(y);
        
        if (rootX != rootY) {
            parent[rootX] = rootY;
            weight[rootX] = weightY * val / weightX;
        }
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                               vector<double>& values, 
                               vector<vector<string>>& queries) {
        
        // Build union-find structure
        for (int i = 0; i < equations.size(); i++) {
            unite(equations[i][0], equations[i][1], values[i]);
        }
        
        vector<double> result;
        result.reserve(queries.size());
        
        for (const auto& query : queries) {
            const string& start = query[0];
            const string& end = query[1];
            
            if (parent.find(start) == parent.end() || 
                parent.find(end) == parent.end()) {
                result.push_back(-1.0);
                continue;
            }
            
            auto [rootStart, weightStart] = find(start);
            auto [rootEnd, weightEnd] = find(end);
            
            if (rootStart != rootEnd) {
                result.push_back(-1.0);
            } else {
                result.push_back(weightStart / weightEnd);
            }
        }
        
        return result;
    }
};