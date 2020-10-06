/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int ans = 0;
        map<char, int> myMap;
        myMap['I'] = 1;
        myMap['V'] = 5;
        myMap['X'] = 10;
        myMap['L'] = 50;
        myMap['C'] = 100;
        myMap['D'] = 500;
        myMap['M'] = 1000;

        for (int i = 0; i < n; i++)
        {
            if(myMap[s[i]] < myMap[s[i+1]])
            {
                ans -= myMap[s[i]];
            }
            else
            {
                ans += myMap[s[i]];
            }
        }

        return ans;
    }
};
// @lc code=end

