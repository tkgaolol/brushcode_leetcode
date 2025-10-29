class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        int n = grid.size();
        int m = grid[0].size();
        const int dirs[5] = {-1, 0, 1, 0, -1};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j]==0) continue;
                else
                {
                    int count = 0;
                    for(int k = 0; k < 4; k++)
                    {
                        int x = i + dirs[k];
                        int y = j + dirs[k + 1];
                        if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y]) count++;
                    }
                    result += 4-count;
                }
            }
        }
        return result;
    }
};