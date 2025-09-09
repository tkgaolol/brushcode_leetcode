class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for(int i = 1; i<prices.size(); i++)
        {
            result += max(prices[i]-prices[i-1], 0);
        }
        return result;
    }
};








class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>> dp (size, vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < size; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[size-1][0];
    }
};