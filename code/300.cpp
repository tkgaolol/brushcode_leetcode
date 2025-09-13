class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size<=1) return size;
        vector<int> dp(size, 1);
        int result = 0;
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if(dp[i]>result) result = dp[i];
        }
        return result;
    }
};