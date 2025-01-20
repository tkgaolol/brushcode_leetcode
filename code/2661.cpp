class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map <int, pair<int,int>> num_to_pose;
        for (int i = 0; i<m; i++)
            for (int j = 0; j<n; j++)
                num_to_pose[mat[i][j]] = {i, j};
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i<arr.size(); i++) {
            auto [x, y] = num_to_pose[arr[i]];
            row[x]++;
            col[y]++;
            if (row[x] == n || col[y] == m)
                return i;
        }
        return -1;
    }
};