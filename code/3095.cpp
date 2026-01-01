class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int result = INT_MAX;
        int orval = 0;
        int init_window = 0;
        int sublength = 0;
        vector<int> count (32, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            orval |= nums[i];
            for(int j = 0; j < 32; j++)
                count[j] += (nums[i] & (1 << j)) ? 1: 0;
            while(orval >= k && init_window <= i)
            {
                sublength = i - init_window + 1;
                result = result > sublength? sublength: result;
                for(int j = 0; j < 32; j++)
                {
                    count[j] += (nums[init_window] & (1 << j))? -1: 0;
                    if(count[j] == 0) orval &= (~(1 << j));
                }
                init_window++;
            }    
        }
        return result==INT_MAX? -1: result;
    }
};