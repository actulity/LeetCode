/*
 * @lc app=leetcode.cn id=355 lang=cpp
 *
 * [355] 设计推特
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <list>

using namespace std;
class Twitter {
    struct Node{
        // 该用户关注的人的id
        unordered_set<int> followee;
        // tweetId
        list<int> tweet;
    };
    int recentMax, time;
    // tweetId 对应发送的时间
    unordered_map<int, int> tweetTime;
    // 映射, 用户id对应用户，存储每个用户存储的信息
    unordered_map<int, Node> user;
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
        recentMax = 10;
        tweetTime.clear();
        user.clear();
    }
    
    void init(int userId){
        user[userId].followee.clear();
        user[userId].tweet.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(user.find(userId) == user.end()){
            init(userId);
        }
        if(user[userId].tweet.size() == recentMax){
            user[userId].tweet.pop_back();
        }
        user[userId].tweet.push_front(tweetId); // 前面的最小
        
        tweetTime[tweetId] = time++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if(user.find(userId) == user.end()) return {};
        vector<int> ans; ans.clear();
        
        for (list<int>::iterator it = user[userId].tweet.begin(); it != user[userId].tweet.end(); ++it) {
            ans.emplace_back(*it);  // emplace 放置、安放
        }
        // 线性归并
        for(int followeeId : user[userId].followee){
            if(followeeId == userId) continue;
            vector<int> res; res.clear();
            list<int> ::iterator it = user[followeeId].tweet.begin();
            int i = 0;
            while(i < ans.size() && it != user[followeeId].tweet.end()){
                if(tweetTime[(*it)] > tweetTime[ans[i]]){
                    res.emplace_back(*it);
                    ++it;
                }
                else{
                    res.emplace_back(ans[i]);
                    ++i;
                }
                if(res.size() == recentMax) break;
            }
            for (; i < (int)ans.size() && (int)res.size() < recentMax; ++i) res.emplace_back(ans[i]);
            for (; it != user[followeeId].tweet.end() && (int)res.size() < recentMax; ++it) res.emplace_back(*it);
            ans.assign(res.begin(), res.end());  //拷贝
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(user.find(followerId) == user.end()) init(followerId);
        if(user.find(followeeId) == user.end()) init(followeeId);
        user[followerId].followee.insert(followeeId); 
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        user[followerId].followee.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

