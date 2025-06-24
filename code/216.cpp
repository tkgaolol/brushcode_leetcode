class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int k, int n, int sum, int startindex)
    {
        if(path.size()==k)
        {
            if (sum == n) 
                result.push_back(path);
            return;
        }
        
        for(int i = startindex; i <= 9; i++)
        {
            sum += i;
            path.push_back(i);
            backtracking(k,n,sum,i+1);
            sum-=i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 0, 1);
        return result;
    }
};