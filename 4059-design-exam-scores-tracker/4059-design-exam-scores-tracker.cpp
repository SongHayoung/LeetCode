
class ExamTracker {
    vector<pair<long long, long long>> pre;
    int find(int x) {
        return lower_bound(begin(pre), end(pre), pair<long long, long long>{x + 1, INT_MIN}) - begin(pre) - 1;
    }
public:
    ExamTracker() {
        pre = {{0,0}};
    }

    void record(int time, int score) {
        pre.push_back({time, pre.back().second + score});
    }

    long long totalScore(int startTime, int endTime) {
        int r = find(endTime), l = find(startTime - 1);
        if(l == r) return 0;
        return pre[r].second - pre[l].second;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * double param_2 = obj->avgScore(startTime,endTime);
 */