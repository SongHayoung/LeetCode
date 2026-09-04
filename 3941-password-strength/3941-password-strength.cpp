class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> lo, up, di, sp;
        for(auto& p : password) {
            if(isdigit(p)) di.insert(p);
            else if(isalpha(p)) {
                if(islower(p)) lo.insert(p);
                else up.insert(p);
            } else sp.insert(p);
        }
        return lo.size() + 2 * up.size() + 3 * di.size() + 5 * sp.size();
    }
};