/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int rightmost = 0;
        int id = 0;
        
        if(n == 1) return 0;
        
        while(rightmost < n){
            int tmp = rightmost;
            for (int i = id; i <= tmp; ++i){
                int index = i + nums[i];
                if(index > rightmost){
                    id = i + 1;
                    rightmost = index;
                }
            }
            ans++;
            if(rightmost >= n - 1) return ans;
            if(tmp == rightmost && rightmost < n - 1) return 0;
        }
        return ans;
    }
};
// @lc code=end

