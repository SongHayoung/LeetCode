class Twitter {
private:
    struct Info {
        int followee;
        int time;
        int tweetId;

        bool operator<(const Info &a) const{
            return this->time < a.time;
        }
    };

    unordered_map<int, set<int>> follows;
    unordered_map<int, list<pair<int,int>>> feeds;
    long time;

    pair<int, int> getNthFeed(int userId, int n) {
        list<pair<int, int>> feedList = feeds[userId];
        if(feedList.size() <= n)
            return {INT_MIN, INT_MIN};

        auto it = feedList.begin();
        advance(it, n);

        return *it;
    }

    Info getNthFeedInfo(int userId, int n) {
        pair<int, int> feed = getNthFeed(userId, n);
        return {userId, feed.first, feed.second};
    }
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        feeds[userId].push_front({time++, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        map<int, int> followings;
        priority_queue<Info> pq;

        for(auto followee : follows[userId]) {
            if(!feeds[followee].empty())
                pq.push(getNthFeedInfo(followee,followings[followee] = 0));
        }
        if(!feeds[userId].empty())
            pq.push(getNthFeedInfo(userId,followings[userId] = 0));

        while(!pq.empty() && res.size() < 10 && pq.top().time != INT_MIN) {
            Info info = pq.top();
            pq.pop();
            res.push_back(info.tweetId);
            pq.push(getNthFeedInfo(info.followee, ++followings[info.followee]));
        }

        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId ^ followeeId)
            follows[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId ^ followeeId)
            follows[followerId].erase(followeeId);
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
