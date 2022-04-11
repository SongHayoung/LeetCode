class Solution {
public:
    string predictPartyVictory(string senate) {
        int rc = 0, dc = 0, skipr = 0, skipd = 0;
        queue<bool> q;
        for(auto& ch : senate) {
            q.push(ch == 'R');
            if(ch == 'R') rc++;
            else dc++;
        }
        while(rc and dc) {
            auto se = q.front(); q.pop();
            if(se) {
                if(skipr) {
                    skipr--;
                    continue;
                }
                dc--; skipd++;
                q.push(se);
            } else {
                if(skipd) {
                    skipd--;
                    continue;
                }
                rc--; skipr++;
                q.push(se);
            }
        }

        return rc ? "Radiant" : "Dire";
    }
};