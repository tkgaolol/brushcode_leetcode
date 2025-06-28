class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int index)
    {
        if(sum==target)
        {
            result.push_back(path);
            return;
        }
        for(int i = index; i<candidates.size()&& sum + candidates[i] <= target; i++)
        {
            if(i > index && candidates[i]==candidates[i-1]) continue;
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum+candidates[i], i+1);
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;    
    }
};