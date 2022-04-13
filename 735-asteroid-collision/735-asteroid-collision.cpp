class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(auto& a : asteroids) {
            if(res.empty()) {
                res.push_back(a);
                continue;
            }
            bool f1, f2 = a > 0;
            while(!res.empty()) {
                f1 = res.back() > 0;
                if((!f1 && f2) || (f1 == f2)) {res.push_back(a); break;} 
                else if(abs(res.back()) == abs(a)) {res.pop_back(); break;}
                else if(abs(res.back()) > abs(a)) {break;}
                else {
                    res.pop_back();
                    if(res.empty()) {
                        res.push_back(a);
                        break;
                    }
                }
            }
        }

        return res;
    }
};