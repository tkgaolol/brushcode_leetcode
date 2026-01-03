class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result(m*n, 1);
        if(m*n == 1)
            return result;
        int row = 0, col = 0, index = 0, num = 0;
        while(num < m*n - 1)
        {
            for(;col < (n-index-1); col++)
                result[num++] = matrix[row][col];
            for(;row < (m-index-1); row++)
                result[num++] = matrix[row][col];
            if(num >= m * n - 1) break;
            for(;col > index; col--)
                result[num++] = matrix[row][col];
            for(;row > index; row--)
                result[num++] = matrix[row][col];
            row++;
            col++;
            index++;
        }
        if(num < m*n) result[num] = matrix[row][col];
        return result;
    }
};