/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(1, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 0; i < n; ++i)
        {
            int min_v = min({ans[p2] * 2, ans[p3] * 3, ans[p5] * 5});
            ans.push_back(min_v);
            if(min_v == ans[p2] * 2) p2++;
            if(min_v == ans[p3] * 3) p3++;
            if(min_v == ans[p5] * 5) p5++;
        }
        return ans[n - 1];
    }
};
// @lc code=end

