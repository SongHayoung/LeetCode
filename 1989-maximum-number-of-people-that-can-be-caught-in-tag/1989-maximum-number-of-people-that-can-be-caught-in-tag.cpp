class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {
        set<int> nit;
        for(int i = 0; i < team.size(); i++) {
            if(team[i] == 0) nit.insert(i);
        }
        int res = 0;
        for(int i = 0; i < team.size() and !nit.empty(); i++) {
            if(team[i] == 0) continue;
            auto p = nit.lower_bound(i-dist);
            if(p == end(nit)) break;
            if(*p <= i + dist) {
                res++;
                nit.erase(p);
            }
        }
        return res;
    }
};