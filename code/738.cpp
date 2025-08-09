class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        if(strNum.size()==1) return n;
        for(int i = 1; i < strNum.size(); i++)
        {
            if(strNum[i-1] - strNum[i] <= 0) continue;
            else
            {
                strNum[i-1]--;
                int j = i;
                while(j < strNum.size())
                {
                    strNum[j] = '9';
                    j++;
                }
                i=0;
                continue;                
            }
        }
        int result = stoi(strNum);
        return result;
    }
};