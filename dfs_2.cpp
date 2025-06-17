#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;
class Solution {
private:
    vector<pair<int,int>> ans;
public:
    void solve(vector<vector<char>>& board) {
    
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !(i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                    dfs(board, i, j);
                    if (!ans.empty()) {
                        for (auto& p : ans) {
                            board[p.first][p.second] = 'X';
                        }
                    }
                    ans.clear();
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'V') {
                    board[i][j] = 'O';  // Restore visited cells to 'O'
                }
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O') return;
        if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) && board[i][j] == 'O') {
            board[i][j] = 'V';
            ans.clear();
            return;
        }
        board[i][j] = 'V';  // Mark as visited
        ans.push_back({i,j});
        
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};