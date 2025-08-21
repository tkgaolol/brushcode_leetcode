class Solution {
public:
    int integerBreak(int n) {
        if(n<=1) return 0;
        if(n==2) return 1;
        vector<int> dp(n+1);
        dp[2] = 1;
        for(int i = 3; i<=n; i++)
        {
            for (int j = 1; j < i - 1; j++) 
            {
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};