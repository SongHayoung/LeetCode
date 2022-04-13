class TopVotedCandidate {
    map<int, int> history;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        vector<int> p(5001, 0); //vote count
        int ma = 0, n = times.size(); //max vote count

        for(int i = 0; i < n; i++) {
            p[persons[i]]++; //update
            if(ma <= p[persons[i]]) { //compare and insert time, person map
                history[times[i]] = persons[i];
            }
            ma = max(ma,p[persons[i]]); //update max value
        }
    }

    int q(int t) {
        auto it = history.upper_bound(t);
        if(it == history.begin()) return -1; // ???? every one is zero when this time
        return (--it)->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */