class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n= triangle[m-1].size();
        vector<int> ans = triangle[m-1];
        for (int i = m-2;i>=0;i--){
            for (int j = 0;j <= i; j++){
                ans[j]= min(ans[j], ans[j+1]) + triangle [i][j];
            }
        }
        return ans[0];
    }
};