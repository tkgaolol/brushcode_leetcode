class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp(size, vector<int>(2*k,0));
        for(int i = 0; i < 2*k; i+=2)
        {
            dp[0][i] = -prices[0];
        }
        for(int i = 1; i < size; i++)
        {
            dp[i][0] = max(dp[i-1][0], 0-prices[i]);
            for(int j = 1; j < 2*k; j++)
            {
                int plus = dp[i-1][j-1]+ prices[i] * ((j % 2)==0 ? -1 : +1);
                dp[i][j] = max(dp[i-1][j], plus);
            }
        }
        return dp[size-1][2*k-1];
    }
};