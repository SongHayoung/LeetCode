class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> skills;
        unordered_map<int, vector<int>> dp;
        int skillId = 0;
        for(auto req : req_skills) {
            skills[req] = skillId++;
        }
        dp.reserve(1<<skillId);
        
        for(int i = 0; i < people.size(); i++) {
            int m = 0;
            for(auto skill : people[i]) {
                if(skills.count(skill)) {
                    m |= (1<<skills[skill]);
                }
            }
            if(m == 0) continue;
            dp[m] = {i};
            for(auto [mask, p] : dp) {
                int comb = mask | m;
                
                if(!dp.count(comb) or dp[comb].size() > p.size() + 1) {
                    dp[comb] = p;
                    dp[comb].push_back(i);
                }
            }
        }
        return dp[(1<<skillId) - 1];
    }
};