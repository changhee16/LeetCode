class Solution {
public:
    int numDistinct(string s, string t) {
        unsigned int dp[1001][1001] = {0,};
        for (int i = 0; i <= s.length(); i++)
            dp[i][0] = 1;
        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 1; j <= t.length(); j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.length()][t.length()];
    }
};