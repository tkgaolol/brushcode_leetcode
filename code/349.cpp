class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set <int> result;
        unordered_set <int> nums(nums1.begin(), nums1.end());
        for(int n:nums2)
        {
            if (nums.find(n) != nums.end()) {
                result.insert(n);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};