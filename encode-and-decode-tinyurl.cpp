class Solution {
    unordered_map<string, string> cache;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = to_string(rand()%31) + to_string(time(0));
        cache[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return cache[shortUrl];
    }
};
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
