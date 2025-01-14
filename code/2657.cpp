class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> dp(A.size(),0);
        int init = 1;
        dp[0] = A[0] == B[0] ? 1 : 0;
        while(init < A.size())
        {
            dp[init] += dp[init-1];
            if(A[init] == B[init])
            {
                ++dp[init];
                init++;
                continue;
            }

            int i=0,j =0;

            while(i<init)
            {
                if(B[init]==A[i])
                {
                    dp[init]++;
                    break;
                }
                i++;
            }

            while(j<init)
            {
                if(A[init]==B[j])
                {
                    dp[init]++;
                    break;
                }
                j++;
            }

            init++;
        }

        return dp;

    }
};