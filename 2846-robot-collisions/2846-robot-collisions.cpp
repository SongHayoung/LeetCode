struct Robot {
    long long ord, pos, hp;
    char dir;
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        deque<Robot> A;
        for(int i = 0; i < positions.size(); i++) {
            A.push_back({i,positions[i], healths[i], directions[i]});
        }
        sort(begin(A), end(A), [](auto a, auto b) {
            return a.pos < b.pos;
        });
        map<long long, long long> mp;
        deque<Robot> r;
        while(A.size()) {
            while(A.size() and A.front().dir == 'L') {
                mp[A.front().ord] = A.front().hp;
                A.pop_front();
            }
            while(A.size() and A.back().dir == 'R') {
                mp[A.back().ord] = A.back().hp;
                A.pop_back();
            }
            while(A.size() and A.front().dir == 'R') {
                r.push_back(A.front()); A.pop_front();
            }
            if(A.size()) {
                while(r.size() and A.size() and A.front().dir == 'L') {
                    if(r.back().hp == A.front().hp) {
                        r.pop_back(); A.pop_front();
                    } else if(r.back().hp > A.front().hp) {
                        A.pop_front();
                        r.back().hp -= 1;
                        cout<<r.back().hp<<endl;
                    } else {
                        r.pop_back();
                        A.front().hp -= 1;
                    }
                }
            }
        }
        while(r.size()) {
            mp[r.back().ord] = r.back().hp;
            r.pop_back();
        }
        vector<int> res;
        for(auto [k,v] : mp) res.push_back(v);
        return res;
    }
};