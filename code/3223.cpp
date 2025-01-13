class Solution {
public:
    int minimumLength(string s) {
        if(s.length()<=2) return s.length();
        int num_of_char[26] = {0};
        for (int i = 0; i<s.length(); i++)
        {
            num_of_char[s[i]-'a']++;
            if(num_of_char[s[i]-'a'] > 2)
            {
                num_of_char[s[i]-'a'] -=2;
            }
        }

        int res = 0;
        for (int i = 0; i<26; i++)
        res+=num_of_char[i];

        return res;

    }
};