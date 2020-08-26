/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

// // @lc code=start
// #include <vector>
// #include <iostream>

// class Solution
// {
// public:
//     vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
//     {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         if (n1 == 0 || n2 == 0)
//             return {};

//         vector<vector<int>> ans(k);
//         if(n1 * n2 < k)
//         {
//             k = n1 * n2;
//             ans.resize(n1 * n2);
//         }
        
//         struct pair_hash
//         {
//             inline size_t operator()(const pair<int, int> &p) const
//             {
//                 return p.first * 10 + p.second;
//             }
//         };
//         unordered_set<pair<int, int>, pair_hash> s;
//         auto cmp = [](const pair<int, int> a, const pair<int, int> b) {
//             return (a.first + a.second) > (b.first + b.second);
//         };

//         priority_queue<
//             pair<int, int>,
//             vector<pair<int, int>>,
//             decltype(cmp)>
//             p(cmp);

//         int index = 0;
//         for (int i = 0; i < n1; ++i)
//         {
//             for (int j = 0; j < n2; j++)
//             {
//                 p.push(pair(nums1[i], nums2[j]));
//                 int tmp = nums1[i] + nums2[j];
//                 while (p.size() > 0 && i < n1 - 1 && tmp < nums1[i + 1] + nums2[0] && index < k)
//                 {
//                     ans[index].push_back(p.top().first);
//                     ans[index].push_back(p.top().second);
//                     p.pop();
//                     tmp = p.top().first + p.top().second;
//                     if (index == k - 1)
//                         return ans;
//                     index++;
//                 }

//             }
//         }

//         for (int i = index; p.size() >= 0 && i < k; ++i)
//         {
//             ans[i].push_back(p.top().first);
//             ans[i].push_back(p.top().second);
//             p.pop();
//         }

//         return ans;
//     }
// };

class Solution
{
public:
    struct cmp
    {
        bool operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
        {
            return a.first + a.second.first > b.first + b.second.first;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {

        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 == 0 || len2 == 0)
        {
            return vector<vector<int>>();
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> q;
        vector<vector<int>> ans;

        for (int i = 0; i < len1; i++)
        {
            pair<int, pair<int, int>> t(nums1[i], pair<int, int>(nums2[0], 0));
            q.push(t);
        }
        for (int i = 0; i < k && !q.empty(); i++)
        {
            pair<int, pair<int, int>> t = q.top();
            q.pop();
            vector<int> s = {t.first, t.second.first};
            ans.push_back(s);
            if (t.second.second < len2 - 1)
            {
                t.second.second++;
                t.second.first = nums2[t.second.second];
                q.push(t);
            }
        }
        return ans;
    }
};
// @lc code=end
