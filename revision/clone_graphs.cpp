#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if (!node) return nullptr;
        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        q.push(node);
        visited[node] = new Node(node->val);
        while(!q.empty()) {
            Node* current = q.front();
            q.pop();
            for (Node* neighbor : current->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[current]->neighbors.push_back(visited[neighbor]);
            }
        }
        return visited[node];
    }
};
//faster , remember to use the limit of nodes to make it faster 
class Solution {
public:

    void dfs(Node* copy, Node* node, vector<Node*>&vis){
        vis[copy->val] = copy;

        for(auto x : node->neighbors){
            if(vis[x->val] == NULL){
                Node* newNode = new Node(x->val);
                copy->neighbors.push_back(newNode);
                dfs(newNode, x, vis);
            }else{
                copy->neighbors.push_back(vis[x->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)
            return NULL;

        vector<Node*>vis(101, NULL);
        Node* copy = new Node(node->val);
        dfs(copy, node, vis);

        return copy;

    }
};