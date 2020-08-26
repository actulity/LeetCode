/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
#include <vector>

bool cmp(int a, int b){
    return a > b;
}

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ch[26] = {0};
        for(char it : tasks)
        {
            ch[it - 'A']++;
        }
        sort(ch, ch + 26, cmp);
        int time = 0;
        while(ch[0] > 0){
            for (int i = 0; i <= n; ++i){
                if(ch[0] == 0)
                    break;
                if(i < 26 && ch[i] > 0)
                    ch[i]--;
                time++;
            }
        
        sort(ch, ch + 26, cmp);
        }
        return time;
    }
};
// @lc code=end

