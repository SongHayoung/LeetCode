class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26]{0};
        for(auto ch : magazine) ++arr[ch-'a'];
        for(auto ch : ransomNote) --arr[ch-'a'];
        for(int i = 0; i < 26; i++) {
            if(arr[i] < 0) return false;
        }
        return true;
    }
};