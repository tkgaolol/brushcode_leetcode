class Solution {
public:
    int robcount(vector<int>& nums, int start, int end)
    {
        if(start==end) return nums[start];
        vector<int> dp (nums.size());
        dp[start] = nums[start];
        dp[start+1] = max(nums[start],nums[start+1]);
        for(int i = start + 2; i <= end; i++)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        return max(robcount(nums, 0, nums.size()-2), robcount(nums, 1, nums.size()-1));
    }
};