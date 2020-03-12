/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// @lc code=start
class Twitter {
    struct msg
    {
        int msgId;
        int token;
        msg(int m, int t):msgId(m), token(t){}
    };

    struct user
    {
        int userId;
        vector<int> followingVec;
        vector<struct msg> messages;
        user(int u):userId(u){}
    };

public:
    /** Initialize your data structure here. */
    Twitter():_token(0) 
    {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) 
    {
        struct msg m = createMsg(tweetId);

        map<int, struct user>::iterator ite = _users.find(userId);
        if (ite != _users.end())
        {
            ite->second.messages.push_back(m);
            return;
        }
        
        struct user u = createUser(userId);
        u.messages.push_back(m);
        _users.insert({userId, u});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> ret;
        vector<struct msg> allMsg;
        
        map<int, struct user>::iterator ite = _users.find(userId);
        if (ite == _users.end())
        {
            return ret;
        }

        vector<struct msg> selfMsg = getUserFeeds(userId);
        allMsg.insert(allMsg.end(), selfMsg.begin(), selfMsg.end());

        for (size_t i = 0; i < ite->second.followingVec.size(); i++)
        {
            int uId = ite->second.followingVec[i];
            vector<struct msg> uMsg = getUserFeeds(uId);
            allMsg.insert(allMsg.end(), uMsg.begin(), uMsg.end());
        }
        
        sort(allMsg.begin(), allMsg.end(), [](struct msg a, struct msg b)
        {
            return a.token > b.token;
        });

        int aSize = allMsg.size();
        size_t num = aSize >= 10 ? 10 : aSize;
        for (size_t i = 0; i < num; i++)
        {
            ret.push_back(allMsg[i].msgId);
        }
        
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {
        map<int, struct user>::iterator ite = _users.find(followerId);
        if (ite != _users.end())
        {
            if (followerId == followeeId)
            {
                return;
            }
            for (size_t j = 0; j < ite->second.followingVec.size(); j++)
            {
                if (ite->second.followingVec[j] == followeeId)
                {
                    return;
                }
            }

            ite->second.followingVec.push_back(followeeId);
        }
        else
        {
            struct user u = createUser(followerId);
            if (followerId != followeeId)
            {
                u.followingVec.push_back(followeeId);
            }

            _users.insert({followerId, u});
        }
        
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {
        map<int, struct user>::iterator ite = _users.find(followerId);
        if (ite != _users.end())
        {
            for (vector<int>::iterator iteV = ite->second.followingVec.begin(); iteV != ite->second.followingVec.end(); iteV++)
            {
                if (*iteV == followeeId)
                {
                    ite->second.followingVec.erase(iteV);
                    return;
                }
            }
        }
        else
        {
            struct user u = createUser(followerId);
            _users.insert({followerId, u});
        }
        
    }

private:
    struct user createUser(int userId)
    {
        struct user u(userId);
        return u;
    };

    struct msg createMsg(int tweetId)
    {
        struct msg m(tweetId, _token);
        _token++;
        return m;
    }

    vector<msg> getUserFeeds(int userId, int num = 10)
    {
        vector<struct msg> ret;
        map<int, struct user>::iterator ite = _users.find(userId);
        if (ite != _users.end())
        {   
            int len = ite->second.messages.size();
            int cnt = 0;
            for (int i = len - 1; i >= 0 && cnt < num; i--, cnt++)
            {
                ret.push_back(ite->second.messages[i]);
            }
        }
        return ret;
    }

    map<int, struct user> _users;
    int _token;
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

