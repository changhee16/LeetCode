#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <long long> m;
    long long MOD = 1'000'000'007LL;
    
    vector<long long> multiply22(vector<long long> a, vector<long long> b)
    {
    vector<long long> res;
    res.push_back( ((a[0] % MOD) * (b[0] % MOD) + (a[1] % MOD) * (b[2] % MOD)) % MOD );
    res.push_back( ((a[0] % MOD) * (b[1] % MOD) + (a[1] % MOD) * (b[3] % MOD)) % MOD );
    res.push_back( ((a[2] % MOD) * (b[0] % MOD) + (a[3] % MOD) * (b[2] % MOD)) % MOD );
    res.push_back( ((a[2] % MOD) * (b[1] % MOD) + (a[3] % MOD) * (b[3] % MOD)) % MOD );
    return res;
    }

    vector<long long> multiply21(vector<long long> a, vector<long long> b)
    {
    vector<long long> res;
    res.push_back( ((a[0] % MOD) * (b[0] % MOD) + (a[1] % MOD) * (b[1] % MOD)) % MOD );
    res.push_back( ((a[2] % MOD) * (b[0] % MOD) + (a[3] % MOD) * (b[1] % MOD)) % MOD );
    return res;
    }  
    //mat^p를 p번 곱하지 않고 log₂(p)번만에 계산하는 알고리즘
    vector <long long> exp_power(vector <long long> m, long long p)
    {
        //항등 행렬 정의
        vector <long long> base = {1, 0, 0, 1};

        while (p > 0)
        {
            if (p & 1)
                base = multiply22(base, m);
            m = multiply22(m, m);
            p >>= 1;
        }
        return base;
    }

    int numberOfWays(string s, string t, long long k) {
        // 1. KMP 계산
        int n = s.size();
        string s_new = s + s.substr(0, n-1);
        vector <int> lps(n, 0);

        //1. lps 배열 만들기 (전처리)
        //i : 현재 LPS를 계산하려는 위치
        //j : 현재까지 일치한 접두사의 길이 
        //lps[i] : i까지의 문자열 중에 접두사와 접미사가 같아지는 가장 긴 길이 
        for (int i = 1, j = 0; i < n; i++)
        {
            while (j > 0 && t[i] != t[j]) j = lps[j - 1]; 
            //while문인 이유:불일치했을 때 j를 줄이는 과정이 한번이 아니라 연속적으로 발생할 수 있기 때문 
            if (t[i] == t[j]) lps[i] = ++j;
        }
        //2. KMP search
        long long good_cnt = 0;
        for (int i = 0, j = 0; i < s_new.size(); i++)
        {
            while (j > 0 && s_new[i] != t[j]) j = lps[j - 1];
            if (s_new[i] == t[j]) j++;
            if (j == n)
            {
                good_cnt++;
                j = lps[j - 1];
            }
        }
        if (good_cnt == 0) return 0; //예외 처리 

        long long bad_cnt = n - good_cnt;
        long long same = (s == t) ? 1 : 0;

        //M 행렬 정의
        m.push_back(good_cnt - 1); //m00
        m.push_back(good_cnt); //m01
        m.push_back(bad_cnt); //m10
        m.push_back(bad_cnt - 1); //m11
        vector <long long> s0 = {same, 1 - same};
        vector <long long> m_k = exp_power(m, k);

        vector <long long> res = multiply21(m_k, s0);
        res[0] = res[0] % MOD;
        res[1] = res[1] % MOD;
        return (int)res[0];
    }
};