class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0;
        bool zero = false;
        for (int i = 0; i < nums.size(); i++) { // 第二步
            if (nums[i] <= 0 && k > 0) {
                nums[i] *= -1;
                k--;
                if(nums[i]==0) zero = true;
            }
            else break;
        }
        sort(nums.begin(), nums.end());
        if (k % 2 == 1 && !zero) nums[0] *= -1;
        for (int a : nums) 
        {
            result += a;
        }
        return result;
    }
};