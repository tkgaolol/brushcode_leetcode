class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27] = {0};
        for(int i = 0; i<s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for(int i = 0; i<s.size(); i++)
        {
            right = max(right, hash[s[i]-'a']);
            if(right == i)
            {
                result.push_back(right + 1 - left);
                left = right + 1;
                right = right + 1;
            }
        }
        return result;

    }
};