class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size()<=1) return stones[0];
        vector<int> dp (1501, 0);
        int sum = 0;
        for(int i: stones) sum += i;
        int target = sum/2;
        for(int i = 0; i< stones.size(); i++)
            for(int j = target; j >= stones[i]; j--)
                dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);

        return sum - dp[target] * 2;
    }
};