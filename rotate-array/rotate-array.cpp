class Solution {
public:
    void rotate(vector <int>& nums, int k) {
        int tmp;
        deque <int> dnums(nums.begin(), nums.end());
        while(k--)
        {
            tmp = dnums[dnums.size() - 1];
            dnums.pop_back();
            dnums.push_front(tmp);
        }
        for (int i = 0; i < nums.size(); i++)
            nums[i] = dnums[i];
    }
};