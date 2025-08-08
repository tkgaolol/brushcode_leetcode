class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return intervals;
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end(), cmp);
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0]<=result[result.size()-1][1])
            {
                result[result.size()-1][1] = max(intervals[i][1], result[result.size()-1][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};