/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxrectcol(int row,vector<vector<int>>& dpu,vector<vector<char>>& matrix){
        
        int m = matrix[0].size();
        vector<int> left (m,0);
        vector<int> right (m,0);
        stack<int> st;
        if (matrix.empty()) return 0;
        for (int j =0 ;j<m;j++){
            while(!st.empty() && dpu[row][j]<= dpu[row][st.top()]){
                st.pop();
            }
            if ( st.empty()) left[j]=0;
            else{
                left[j]= st.top()+1;
            }
            st.push(j);
        }
        stack<int> st2;
        st =st2;
        for (int j =m-1 ;j>=0;j--){
            while(!st.empty() && dpu[row][j]<= dpu[row][st.top()]){
                st.pop();
            }
            if ( st.empty()) right[j]=m-1;
            else{
                right[j]= st.top()-1;
            }
            st.push(j);
        }
        int maxi =0;
        for (int j =0 ;j<m;j++){
            maxi = max(maxi, dpu[row][j]*(right[j]-left[j]+1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dpu(n,vector<int> (m,0));
        
        for (int j =0 ;j<m;j++){
                dpu[0][j] =matrix[0][j]-'0';
            }
         
        int maxi = 0;
        maxi = max(maxi, maxrectcol(0, dpu, matrix));
        for (int i =1 ;i<n;i++){ 
            for (int j =0 ;j<m;j++){
                if (matrix[i][j] =='1'){
                    dpu[i][j]=matrix[i][j] -'0'+dpu[i-1][j];
                }
                
                
            }
            maxi = max(maxi,maxrectcol(i,dpu,matrix));
        }
        return maxi;
    }
};
// @lc code=end

