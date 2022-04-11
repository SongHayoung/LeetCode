class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        map<int, long long> meals;
        set<int> powerOfTwo;
        for(int i = 0; i <= 21; i++) {
            powerOfTwo.insert(1<<i);
        }
        long long res = 0;

        for(int num : deliciousness) {
            meals[num]++;
        }

        for(auto meal : meals) {
            for(auto num = powerOfTwo.lower_bound(meal.first<<1); num != powerOfTwo.end(); num++) {
                auto it = meals.lower_bound(*num - meal.first);
                if(it == meals.end())
                    break;
                if(it->first + meal.first == *num) {
                    if(it->first == meal.first)
                        res += it->second * (meal.second - 1) / 2;
                    else
                        res += it->second * meal.second;
                }
            }
        }

        return res % 1000000007;
    }
};
