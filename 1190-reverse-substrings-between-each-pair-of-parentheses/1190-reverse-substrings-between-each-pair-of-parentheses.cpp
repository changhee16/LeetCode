class Solution {
public:
    string reverseParentheses(string s) {
        stack <int> start;
        queue <int> end;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                start.push(i);
            else if (s[i] == ')')
            {
                int s_idx = start.top();
                start.pop();
                reverse(s.begin() + s_idx + 1, s.begin() + i);
            }
        }
        string res = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '(' && s[i] != ')')
                res += s[i];
        }        
        return res;
    }
};