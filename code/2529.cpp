class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int left = 0, right = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[left]<0)left++;
            if(nums[nums.size() -1 - right]>0)right++;
        }
        if(left > right)return left;
        else return right;
    }
};