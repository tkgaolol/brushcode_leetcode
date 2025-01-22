class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1)); // Initialize heights to -1
        queue<pair<int, int>> q;
        
        // Initialize water cells with height 0 and add to queue
        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                if(isWater[i][j] == 1) 
                {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Directions for adjacent cells (up, right, down, left)
        vector<pair<int, int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        
        // BFS to assign heights
        while(!q.empty()) 
        {
            auto [i, j] = q.front();
            q.pop();
            
            // Check all adjacent cells
            for(auto [di, dj] : dirs) 
            {
                int ni = i + di;
                int nj = j + dj;
                
                // If adjacent cell is valid and unassigned
                if(ni >= 0 && ni < m && nj >= 0 && nj < n && height[ni][nj] == -1) 
                {
                    height[ni][nj] = height[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
        
        return height;
    }
};