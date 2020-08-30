/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int bit = 1 << n;
        vector<vector<int>> ans;
        for (int i = 0; i < bit; ++i)
        {
            vector<int> v;
            for (int j = 0; j < n; ++j)
            {
                if(i & (1 << j))
                    v.push_back(nums[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
// @lc code=end

