/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for(int it : nums)
        {
            single ^= it;
        }
        return single;
    }
};
// @lc code=end

