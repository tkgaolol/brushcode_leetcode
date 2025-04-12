class Solution {
public:
    bool isHappy(int n) {
        unordered_set <int> sum_set;
        while(true)
        {
            int sum = 0;
            while (n) 
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if(sum==1)
                return true;
            else
            {
                if(sum_set.find(sum)!=sum_set.end())
                    return false;
                else
                    sum_set.insert(sum);
            }
            n = sum;
        }
    }
};