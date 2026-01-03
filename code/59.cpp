class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n,1));
        int row = 0, col = 0, index = 0, num = 1;;
        if(n == 1)
            return result;
        while(num < n*n)
        {
            for(; col<(n-index-1); col++)
                result[row][col] = num++;
            for(; row<(n-index-1); row++)
                result[row][col] = num++;
            for(; col>index; col--)
                result[row][col] = num++;
            for(; row>index; row--)
                result[row][col] = num++;
            row++;
            col++;
            index++;
        }
        if(n%2) result[row][col] = num;
        return result;
    }
};