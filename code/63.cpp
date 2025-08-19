class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[n - 1][m - 1] == 1 || obstacleGrid[0][0] == 1)
            return 0;
        vector<vector<int>> dp (n,vector<int>(m,0));
        for(int i = 0; i < n  && obstacleGrid[i][0] == 0; i++)  dp[i][0]=1;
        for(int i = 0; i < m  && obstacleGrid[0][i] == 0; i++) dp[0][i]=1;
        for(int i = 1; i<n; i++)
        {
            for(int j = 1; j<m; j++)
            {
                if(obstacleGrid[i][j]==1) dp[i][j] = 0;
                else dp[i][j] += dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};