class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<=1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int result = 0;
        unordered_set<int> eraseitems;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i-1][1] > intervals[i][0])
            {
                result++;
                intervals[i][1] = min(intervals[i-1][1], intervals[i][1]);
            }
        }
        return result;
    }
};