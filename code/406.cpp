class Solution {
public:
    static bool cmp(vector<int>& p1, vector<int>& p2)
    {
        if(p1[0]==p2[0]) return p1[1]<p2[1];
        return p1[0] > p2[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> que;
        for(int i = 0; i < people.size(); i++)
        {
            int position = people[i][1];
            std::list<vector<int>>::iterator it = que.begin();
            while(position--)
            {
                it++;
            }
            que.insert(it, people[i]);
        }
        return vector<vector<int>>(que.begin(), que.end());
        
    }
};