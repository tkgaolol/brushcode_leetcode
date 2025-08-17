class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n<=1) return 0;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 1; i < cost.size(); i++)
        {
            dp[i+1] = min(dp[i]+cost[i],dp[i-1]+cost[i-1]);
        }
        return dp[n];
    }
};