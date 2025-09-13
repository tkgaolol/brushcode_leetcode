class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int size = nums.size();
        if(size<=1) return size;
        vector<int> dp(size,1);
        int result = 1;
        for(int i = 1; i < size; i++)
        {
            if(nums[i]>nums[i-1]) dp[i]=dp[i-1]+1;
            if(dp[i] > result) result = dp[i];
        }
        return result;
    }
};