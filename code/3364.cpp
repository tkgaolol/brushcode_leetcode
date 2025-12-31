class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        long long best = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            for (int len = 1; len <= r && i - len + 1 >= 0; ++len) {
                sum += nums[i - len + 1];
                if (len >= l && sum > 0) best = min(best, sum);
            }
        }
        return best == LLONG_MAX ? -1 : (int)best;
    }
};