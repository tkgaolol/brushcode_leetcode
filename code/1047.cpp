class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for(char i : s) {
            if(result.empty() || result.back() != i) {
                result.push_back(i);
            }
            else {
                result.pop_back();
            }
        }
        return result;
    }
};