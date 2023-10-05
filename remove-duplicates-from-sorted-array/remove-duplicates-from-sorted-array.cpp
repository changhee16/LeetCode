class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> newnums;
        int tmp = 999;
        for (int i = 0; i < nums.size(); i++)
        {
            if (tmp != nums[i])
            {
                newnums.push_back(nums[i]);
                tmp = nums[i];
                nums[newnums.size() - 1] = tmp;
            }
            else
                continue ;
        }
        
       return newnums.size();
    }
};