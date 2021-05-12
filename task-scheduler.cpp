class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(!n) return tasks.size();
        queue<tuple<char, int, int>> delay;
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> m;
        for(auto& c : tasks){
            m[c]++;
        }
        for(auto& e : m) {
            pq.push({e.second, e.first});
        }

        int res = 0;
        while(!pq.empty() || !delay.empty()) {
            if(!delay.empty() && get<2>(delay.front()) + n < res) {
                pq.push({get<1>(delay.front()), get<0>(delay.front())});
                delay.pop();
            }
            if(!pq.empty()) {
                auto p = pq.top();
                pq.pop();
                if(p.first != 1) {
                    delay.push({p.second, p.first - 1, res});
                }
            }

            res++;
        }
        return res;
    }
};
