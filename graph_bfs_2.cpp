#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        queue <pair<string,int>> q;
        q.push({startGene,0});
        st.erase(startGene);

        while(!q.empty()){
            string gene = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (gene == endGene) return steps;
            for (int i = 0; i <8; i++){
                char original = gene[i];
                for (char c : "ACGT"){
                    gene[i] = c;
                    if (st.find(gene) != st.end()){
                        st.erase(gene);
                        q.push({gene,steps+1});
                    }
                }
                gene[i] = original;
            }
        }
        return -1;
    }
};