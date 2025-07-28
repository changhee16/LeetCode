class Solution {
public:
    string longestPalindrome(string s) {
        int s_len = s.size();
        int max_len = 1;
        int start_idx = 0; 
        vector<vector<bool>> dp(s_len, vector<bool>(s_len, false));
        //길이가 1일 때랑 2일때랑 3일때를 나눠서 접근하며, 3일때 DP의 기존 정보 써먹기가 이용됨
        //길이가 1일때는 항상 palindrome
        //DP는 bool형태로 True/False만 알려주고, 길이는 인덱스가 알려줌 
        for (int i = 0; i < s_len; i++)
            dp[i][i] = true;
        for(int i = s_len - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < s_len; j++)
            {
                int length = j - i + 1;
                if (length == 2 && s[i] == s[j])
                    dp[i][j] = true;
                if (length > 2 && ((i+1) <= (j-1)) && s[i] == s[j] && dp[i+1][j-1])
                    dp[i][j] = true;
                if (length > max_len && dp[i][j])
                {
                    max_len = length;
                    start_idx = i;
                }
            }
        }
        return s.substr(start_idx, max_len);
    }
};