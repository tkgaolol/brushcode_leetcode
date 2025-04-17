class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());

        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            unordered_set<int> set;
            
            for (int k = i + 1; k < nums.size(); k++) {
                if (k > i + 2 && nums[k] == nums[k - 1] && nums[k - 1] == nums[k - 2])
                    continue;
                
                int target = 0 - (nums[i] + nums[k]);
                if (set.find(target) != set.end()) {
                    result.push_back({nums[i], target, nums[k]}); 
                    set.erase(target);
                }
                else {
                    set.insert(nums[k]); 
                }
            }
        }
        return result;
    }
};