#include <algorithm>
//1. c++ stl 사용 버전 
class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> res;
        sort(nums.begin(), nums.end()); //오름차순으로 정렬
        res.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()))
            res.push_back(nums);
        return res;
    }
};

