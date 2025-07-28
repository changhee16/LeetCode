class Solution {
public:
    string expand_mid(int left, int right, string s) {
        while (left >= 0 && right < s.size() && (s[left] == s[right])) {
            left--;
            right++;
        }
        //cout << "left: " << left << " right: " << right<<  "\n";
        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {
        string max_str = "";
        for (int i = 0; i < s.size(); i++)
        {
            string odd_substr = expand_mid(i, i, s);
            //cout << "odd_substr: " << odd_substr<<"\n";
            string even_substr = expand_mid(i, i+1, s);
            //cout << "even_substr: " << even_substr<<"\n";
            if (odd_substr.size() > max_str.size())
                max_str = odd_substr;
            if (even_substr.size() > max_str.size())
                max_str = even_substr;
        }
        return max_str;
    }
};