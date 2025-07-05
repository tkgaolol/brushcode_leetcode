class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(const vector<int>& nums, int index)
    {
        result.push_back(path);
        if(index>=nums.size()) return;
        for(int i = index; i<nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};