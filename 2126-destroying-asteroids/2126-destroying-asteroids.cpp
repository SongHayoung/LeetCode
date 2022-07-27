class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));
        for(auto& a : asteroids) {
            if(mass >= a) mass += a;
            else return false;
        }
        return true;
    }
};