class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int c = 0;
        for (int i = 0; i < 30; i++)
            c += (num2 >> i) & 1;

        int cnt = 0, ans = 0;
        for (int i = 29; i >= 0; i--) {
            if ((num1 >> i) & 1) {
                if (cnt < c) {
                    cnt++;
                    ans |= 1 << i;
                }
            } else {
                if (cnt + i < c)
                    ans |= 1 << i;
            }
        }

        return ans;

    }
};