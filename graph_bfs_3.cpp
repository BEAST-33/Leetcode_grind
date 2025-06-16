#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue <pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        unordered_map<int, unordered_set<char>> uniqueLetters;
        int n = beginWord.size();
        // Add characters from beginWord
        for (int i = 0; i < n; i++) {
            uniqueLetters[i].insert(beginWord[i]);
        }
        // Add characters from other words
        for (int i = 0; i < n; i++) {
            for (const string& word : st) {
                uniqueLetters[i].insert(word[i]);
            }
        }
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            if (word == endWord) return steps;
            for (int i = 0; i < word.size(); i++){
                char original = word[i];
                for (char c : uniqueLetters[i]){
                    word[i] = c;
                    if (st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};

int main(){
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << sol.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}