class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);
        vector<int> window(128, 0);
        for(char c: t)
            need[c]++;
        int m = s.length(), n = t.length();
        int cnt = 0, windowlength = m + 1, k = -1;
        for(int l = 0, r = 0; r < m; r++)
        {
            char c = s[r];
            if(++window[c] <= need[c])
                cnt++;
            
            while(cnt == n)
            {
                if(r - l + 1 < windowlength)
                {
                    windowlength = r - l + 1;
                    k = l;
                }
                c = s[l];
                if(window[c] <= need[c])
                    --cnt;
                --window[c];
                ++l;
            }
        }
        return k < 0? "": s.substr(k, windowlength);
    }
};