class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0;
        int sublength = 0;
        int init_window = 0;
        for(int j = 0; j<nums.size(); j++)
        {
            sum += nums[j];

            while(sum>=target)
            {
                sublength = j-init_window+1;
                result = result < sublength? result: sublength;
                sum -= nums[init_window++];
            }
        }
        return result == INT32_MAX? 0: result;

    }
};