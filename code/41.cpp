class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int slow = -1, result = 1;
        sort(nums.begin(), nums.end());
        for(int fast = 0; fast < nums.size(); fast++)
        {
            if(nums[fast]<=0) continue;
            else if(slow == -1)
            {
                if(nums[fast]>1) return 1;
                slow = fast;
                continue;
            }

            if(nums[fast]<=(nums[slow]+1))
                slow = fast;
            else
                return nums[slow]+1;
        }
        return nums[nums.size()-1]>=1? nums[nums.size()-1]+1: 1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};