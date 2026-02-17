class Solution {
public:
    long long numberOfWays(string s) {
        long long s_len = s.length();
        long long total0 = 0, total1 = 0;
        long long left0 = 0, left1 = 0;
        long long right0 = 0, right1 = 0, res = 0;

        for (int i = 0; i < s_len; i++)
        {
            if (s[i] == '0')
                total0++;
            else
                total1++;
        }

        right0 = total0;
        right1 = total1;

        for (int i = 0; i < s_len; i++)
        {
            if (s[i] == '0')
            {
                res += right1 * left1;
                right0 = total0 - ++left0;
            }
            else
            {
                res += right0 * left0;
                right1 = total1 - ++left1;
            }
        }        
        return res;
    }
};