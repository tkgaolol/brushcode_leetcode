class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for(int i = 1; i<prices.size(); i++)
        {
            result += max(prices[i]-prices[i-1], 0);
        }
        return result;
    }
};