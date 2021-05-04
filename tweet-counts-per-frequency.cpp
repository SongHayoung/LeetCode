class TweetCounts {
    unordered_map<string, multiset<int>> tweet;
    unordered_map<string, int> intervals {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
public:
    TweetCounts() {

    }

    void recordTweet(string tweetName, int time) {
        tweet[tweetName].insert(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> res;
        int interval = intervals[freq];
        int from = startTime;
        int to = min(startTime + interval - 1, endTime);
        auto fromIt = lower_bound(tweet[tweetName].begin(), tweet[tweetName].end(), from);
        auto toIt = upper_bound(tweet[tweetName].begin(), tweet[tweetName].end(), to);
        while(to != endTime) {
            if(fromIt != end(tweet[tweetName]) && from <= *fromIt && *fromIt <= to) {
                res.push_back(std::distance(fromIt, toIt));
                fromIt = toIt;
            }
            else {
                res.push_back(0);
            }
            from += interval;
            to = min(from + interval - 1, endTime);
            toIt = upper_bound(tweet[tweetName].begin(), tweet[tweetName].end(), to);
        }
        if(fromIt != end(tweet[tweetName]) && from <= *fromIt && *fromIt <= to) {
            res.push_back(std::distance(fromIt, toIt));
            fromIt = toIt;
        }
        else {
            res.push_back(0);
        }

        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
