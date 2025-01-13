class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n == 0 || n % 2) return false;

        int balance = 0, unlocked = 0;
        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '0') unlocked++;
            else if (s[i] == '(') balance++;
            else balance--;

            if ((balance + unlocked) < 0) return false;
        }

        balance = 0, unlocked = 0;
        for (int i = n-1; i >= 0; i--)
        {
            if (locked[i] == '0') unlocked++;
            else if (s[i] == ')') balance++;
            else balance--;

            if ((balance + unlocked) < 0) return false;
        }
        return true;
    }
};