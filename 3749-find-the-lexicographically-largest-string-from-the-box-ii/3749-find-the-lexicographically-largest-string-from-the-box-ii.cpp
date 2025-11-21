class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word;
        int i = 0, j = 1, n = word.size(), len = word.size() - numFriends + 1;

        while(j < n) {
            int k = 0;
            while(j + k < n and word[i+k] == word[j+k]) k++;
            if(j + k < n and word[i + k] < word[j + k]) {
                int tmp = i;
                i = j;
                j = max(j + 1, tmp + k + 1);
            } else j = j + k + 1;
        }


        string res = "";
        for(; i < word.size() and res.size() < len; i++) res.push_back(word[i]);
        return res;
    }
};