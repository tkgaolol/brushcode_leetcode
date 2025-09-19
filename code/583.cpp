class Solution {
public:
    int minDistance(string word1, string word2) {
        int a = word1.size();
        int b = word2.size();
        vector<vector<int>> dp (a+1, vector<int>(b+1,0));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                if(word1[i]!=word2[j])  dp[i+1][j+1] = min(dp[i][j]+2, min(dp[i][j+1]+1, dp[i+1][j]+1));
                else dp[i+1][j+1] = dp[i][j];
            }
        }
        return dp[a][b];
    }
};