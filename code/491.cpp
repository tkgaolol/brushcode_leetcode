class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(const vector<int>& nums, int index)
    {
        if(path.size()>=2)
        {
            result.push_back(path);
        }
        if(index>=nums.size()) return;
        int used[201] = {0};
        for(int i = index; i<nums.size(); i++)
        {
            if((i>0 && !path.empty() && nums[i]<path.back())|| used[nums[i] + 100] == 1) continue;
            used[nums[i] + 100] = 1;
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};