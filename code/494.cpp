class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) sum += nums[i];
        if(abs(target) > sum) return 0;
        if ((target + sum) % 2 == 1) return 0;
        int bagSize = (target + sum) / 2;

        vector<vector<int>> dp(n, vector<int>(bagSize + 1, 0));
        
        if (nums[0] <= bagSize) dp[0][nums[0]] = 1; 
        dp[0][0] = 1; 

        int numZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) numZero++;
            dp[i][0] = (int) pow(2.0, numZero);
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= bagSize; j++) {
                if (nums[i] > j) dp[i][j] = dp[i - 1][j]; 
                else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
            }
        }
        return dp[nums.size() - 1][bagSize];
    }
};