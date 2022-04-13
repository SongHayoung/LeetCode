/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    int match(string& origin, string& target) {
        int count = 0;
        for(int i = 0; i < origin.length(); i++) {
            if(origin[i] == target[i]) count++;
        }
        return count;
    }

    void removeUnMatchStrings(vector<string>& words, string& picked, int matchCountFromMaster) {
        for(int i = 0; i < words.size(); i++) {
            int matchCount = match(picked, words[i]);
            if(matchCount != matchCountFromMaster){
                words.erase(words.begin() + i);
                i--;
            }
        }
    }

    string pickOne(vector<string>& words) {
        int arr[6][26]{0};
        for(auto& w: words) {
            for(int i = 0; i < 6; i++) {
                arr[i][w[i]-'a']++;
            }
        }
        int idx = 0, ch = 0, ma = 0;
        for(int i = 0; i < 6; i++) {
            int maxIdx, maxValue = 0;
            for(int j = 0; j < 26; j++) {
                if(arr[i][j] > maxValue) {
                    maxIdx = j;
                    maxValue = arr[i][j];
                }
            }
            if(ma < maxIdx) {
                ma = maxIdx;
                ch = maxIdx;
                idx = i;
            }
        }
        for(auto& w : words) {
            if(w[idx]-'a' == ch) return w;
        }
        return "";
    }

public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<pair<string, int>> history;
        for(int i = 0; i < 10 and !wordlist.empty(); i++) {
            string pick = pickOne(wordlist);
            int masterMatchCount = master.guess(pick);
            removeUnMatchStrings(wordlist, pick, masterMatchCount);
        }
    }
};