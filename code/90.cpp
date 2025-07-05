class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (const vector<int>& nums, int index, vector<bool> used)
    {
        result.push_back(path);
        if(index>=nums.size()) return;
        for(int i = index; i< nums.size(); i++)
        {
            if(i>0 && nums[i]==nums[i-1] && used[i-1]==false) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i+1, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, 0, used);
        return result;
    }
};