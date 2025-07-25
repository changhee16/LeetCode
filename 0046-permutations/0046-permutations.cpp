#include <algorithm>
//1. c++ stl 사용 X버전. iterative 호출 
class Solution {
public:

    bool nextPermutation(vector<int>& data)
    {
	int i = data.size() - 1, j = data.size() - 1;
 
	/* 1번 : 꼭대기 찾기 */
	while (i > 0 && data[i - 1] >= data[i]) i--;
	if (i == 0) return false;
 
	/* 2번 j값 찾기 */
	while (data[i - 1] >= data[j]) j--;
	swap(data[i - 1], data[j]);		// 3번 스왑하기
 
	/* 4번 나머지 정렬하기 */
	j = data.size() - 1;
	for (; i < j; ++i, --j)
		swap(data[i], data[j]);
	return true;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int>> res;
        sort(nums.begin(), nums.end()); //오름차순으로 정렬
        res.push_back(nums);
        while (nextPermutation(nums))
            res.push_back(nums);
        return res;
    }
};

