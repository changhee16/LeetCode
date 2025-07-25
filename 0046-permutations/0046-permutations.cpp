#include <algorithm>
//1. c++ stl 사용 X버전. 재귀 호출 버전 (백트래킫)
class Solution {
public:
    vector <vector <int>> res;
    void backtracking(vector<int>& nums, int depth)
    {
        if (depth == nums.size())
        {
            //cout << nums << "\n";
            res.push_back(nums);
            return ;
        }
        for (int i = depth; i < nums.size(); i++) //이부분이 핵심 
        {
            swap(nums[depth], nums[i]);
            backtracking(nums, depth+1);
            swap(nums[depth], nums[i]); 
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        backtracking(nums, 0);
        return res;
    }
};

