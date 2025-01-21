class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> top(n), bottom(n);
        
        // Convert to long long and create prefix sums
        top[0] = grid[0][0];
        bottom[0] = grid[1][0];
        for(int i = 1; i < n; i++) {
            top[i] = top[i-1] + grid[0][i];
            bottom[i] = bottom[i-1] + grid[1][i];
        }
        
        long long result = LLONG_MAX;
        // Try each possible transition point for Robot 1
        for(int i = 0; i < n; i++) {
            // For each transition point i:
            // Robot 2 can either take remaining top path (after i) or bottom path (before i)
            long long remainingTop = i < n-1 ? top[n-1] - top[i] : 0;
            long long remainingBottom = i > 0 ? bottom[i-1] : 0;
            
            // Take maximum of two possible paths for Robot 2
            long long robot2Score = max(remainingTop, remainingBottom);
            // Keep track of minimum possible score for Robot 2
            result = min(result, robot2Score);
        }
        
        return result;
    }
};