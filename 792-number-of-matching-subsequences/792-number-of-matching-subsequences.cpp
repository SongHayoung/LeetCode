class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> arr(26, vector<int>());
        for(int i = 0; i < s.length(); i++) { //push index char of S
            arr[s[i] - 'a'].push_back(i);
        }
        
        int res = 0;
        
        for(auto& word : words) { //O(m n log k)
            int index = 0;
            bool match = true;
            for(auto ch : word) { //find each word can be in smallest index
                auto it = lower_bound(arr[ch-'a'].begin(), arr[ch-'a'].end(), index);
                if(it == arr[ch-'a'].end()) {
                    match = false;
                    break;
                }
                index = *it + 1;
            }
            if(match) res += 1;
        }
        
        return res;
    }
};