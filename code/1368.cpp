class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        // Directions: right, left, down, up
        vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        deque<pair<int, int>> dq;
        
        // Start from (0,0)
        dist[0][0] = 0;
        dq.push_front({0, 0});
        
        while (!dq.empty()) {
            auto [i, j] = dq.front();
            dq.pop_front();
            
            // Try all four directions
            for (int d = 0; d < 4; d++) {
                int ni = i + dirs[d].first;
                int nj = j + dirs[d].second;
                
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    int cost = (grid[i][j] == d + 1) ? 0 : 1;
                    if (dist[i][j] + cost < dist[ni][nj]) {
                        dist[ni][nj] = dist[i][j] + cost;
                        if (cost == 0) {
                            dq.push_front({ni, nj});
                        } else {
                            dq.push_back({ni, nj});
                        }
                    }
                }
            }
        }
        
        return dist[m-1][n-1];
    }
};