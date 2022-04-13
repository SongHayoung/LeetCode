class Solution
{
public:
    bool verify(const string &str1, const string &str2, unordered_map<char, int> &letter_rank)
    {
        int size = min(str1.size(), str2.size());

        for (int i = 0; i < size; i++)
        {
            int s1 = letter_rank[str1[i]];
            int s2 = letter_rank[str2[i]];

            if (s1 == s2)
                continue;
            else if (s1 > s2)
                return false;
            else if (s1 < s2)
                return true;
        }

        if (str1.size() > str2.size())
            return false;
        else
            return true;
    }

    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> letter_rank;

        int count = 0;
        for (const auto &letter : order)
            letter_rank[letter] = ++count;

        for (int i = 0; i < words.size() - 1; i++)
        {
            if (!verify(words[i], words[i + 1], letter_rank))
                return false;
        }

        return true;
    }
};