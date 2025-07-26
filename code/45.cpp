class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0;
        int curdistance = 0;
        int nextdistance =0;
        for(int i = 0; i < nums.size()-1; i++)
        {
            nextdistance = max(i+nums[i], nextdistance);
            if(i==curdistance)
            {
                result++;
                curdistance = nextdistance;
                if(curdistance >= nums.size()-1) break;
            }
        }
        return result;
    }
};