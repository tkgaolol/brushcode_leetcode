class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int a = s.size();
        vector<vector<int>> dp (a, vector<int> (a,0));
        int result = 0;
        for (int i = 0; i < a; i++) dp[i][i] = 1;
        for(int i = a-1; i >= 0; i--)
        {
            for(int j = i+1; j < a; j++)
            {
                if(s[i]==s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else 
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};