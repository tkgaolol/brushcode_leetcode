class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result (n, vector<int>(n, 0));
        int row = 0;
        int col = 0;
        int index = 0;
        int num = 1;
        if(n==1)
        {
            result[0][0] = 1;
            return result;
        }
        while(num<n*n)
        {
            for(; col<(n-index-1); col++)
            {
                result[row][col] = num++;
            }

            for(; row<(n-index-1); row++)
            {
                result[row][col] = num++;
            }

            for(; col>index; col--)
            {
                result[row][col] = num++;
            }

            for(; row>index; row--)
            {
                result[row][col] = num++;
            }

            row++;
            col++;
            index++;
            // n--;

        }
        if(row==index && col==index && result[row][col]==0)
        {
            result[row][col] = num++;
        }
        
        return result;
    }
};