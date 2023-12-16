class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26]{0};
        for(auto& ch : s) ++arr[ch-'a'];
        for(auto& ch : t) --arr[ch-'a'];

        for(int i = 0; i < 26; i++)
            if(arr[i]) return false;
        return true;
    }
};
