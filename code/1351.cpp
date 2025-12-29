class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for(int i = 0; i < grid.size(); i++)
            result += grid[i].end()-lower_bound(grid[i].begin(), grid[i].end(), -1, greater<int>());
        return result;
    }
};