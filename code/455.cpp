class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int result = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;
        for(int i = g.size() - 1; i>=0 && index >= 0;i--)
        {
            if(g[i] <= s[index])
            {
                result++;
                index--;
            }
        }






        return result;
    }
};