/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
            return false;
        int n = A.size();
        int index = 0;
        vector<int> v;
        for (int i = 0; i < n; ++i){
            if(A[i] != B[i]&& index == 0) {
                v.push_back(A[i]);
                v.push_back(B[i]);
                index++;
                continue;
            }
            if(A[i] != B[i]&& index == 1) {
                v.push_back(A[i]);
                v.push_back(B[i]);
                index++;
                continue;
            }
            if(A[i] != B[i])
                index++;
        }
        if(index == 0){
            sort(A.begin(), A.end());
            bool flag = false;
            for (int i = 0; i < n - 1; ++i){
                if (A[i] == A[i+1])
                    flag = true;
            }
            return flag;
        }
        else if(index != 2)
            return false;
        else
        {
            if(v[0] == v[3] && v[1] == v[2]){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
// @lc code=end

