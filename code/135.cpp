class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()<=0) return 0;
        vector<int> candy(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++)
            if(ratings[i]> ratings[i-1]) candy[i] = candy[i - 1] + 1;
        for(int i = ratings.size() - 2; i >= 0 ; i--)
            if(ratings[i]> ratings[i+1])
                candy[i] = max(candy[i], candy[i + 1] + 1);
        int result = 0;
        for(int i = 0; i< candy.size(); i++)
            result += candy[i];

        return result;
    }
};