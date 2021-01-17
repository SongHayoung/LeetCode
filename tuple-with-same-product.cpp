class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        map<int, int> multiplies;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                multiplies[nums[i] * nums[j]]++;
            }
        }
        int answer = 0;
        for(auto it = multiplies.begin(); it != multiplies.end(); it++) {
            answer += ((it->second) * (it->second - 1))<< 2;
        }

        return answer;
    }
};
