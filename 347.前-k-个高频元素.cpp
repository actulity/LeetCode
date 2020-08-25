/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans(k);
        unordered_map<int, int> mp;
        for (auto it : nums)
        {
             mp[it]++;
        }
        auto lambda = [](const pair<int, int> a, const pair<int, int> b)
        {
            return a.second < b.second;
        };

        priority_queue <
            pair<int, int>,
            vector<pair<int, int>>,
            decltype(lambda)> 
        heap(lambda);
        
        for (auto p : mp) {
            heap.push(p);
        }
        
        for (int i = 0; i < k; ++i) {
            ans[i] = heap.top().first;
            heap.pop();
        }
        return ans;
    }
};

// @lc code=end

