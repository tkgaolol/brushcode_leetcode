class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int predif = 0, curdif = 0;
        int result = 1;
        for(int i = 0; i<nums.size() - 1; i++)
        {
            curdif = nums[i+1] - nums[i];
            if((predif>=0 && curdif<0)||(predif<=0 && curdif>0))
            {
                result++;
                predif = curdif;
            }
        }
        return result;
    }
};