class Solution {
public:
    vector<string> result;
    string path;
    void backtracking(string &s, int index, int pointnum)
    {
        if(pointnum ==3)
        {
            if (valid(s, index, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for(int i = index; i < s.size(); i++)
        {
            if(valid(s, index, i))
            {
                s.insert(s.begin() + i + 1 , '.');  // 在i的后面插入一个逗点
                pointnum++;
                backtracking(s, i + 2, pointnum);   // 插入逗点之后下一个子串的起始位置为i+2
                pointnum--;                         // 回溯
                s.erase(s.begin() + i + 1);
            }
            else
                break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0, 0);
        return result;
    }
    bool valid(const string &s, int start, int end)
    {
        if(start > end) return false;

        if (s[start] == '0' && start != end) {
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') {
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
     }

};