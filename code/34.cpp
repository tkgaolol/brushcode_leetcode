class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int left = 0, right = n;
        while(left <= right)
        {
            if(nums[left] == target && nums[right] == target) return vector<int>{left,right};
            if(nums[left] != target) left++;
            if(nums[right] != target) right--;
        }
        return vector<int>{-1,-1};
    }
};