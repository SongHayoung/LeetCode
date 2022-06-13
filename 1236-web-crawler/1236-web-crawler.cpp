/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
    string getHost(string& url) {
        int i = 7;
        string host = "";
        while(i < url.length() and url[i] != ':' and url[i] != '/') {
            host.push_back(url[i++]);
        }
        return "http://" + host;
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<string> res{startUrl};
        queue<string> q;
        unordered_set<string> vis{startUrl};
        q.push(startUrl);
        string host = getHost(startUrl);
        while(!q.empty()) {
            auto url = q.front(); q.pop();
            for(auto& near : htmlParser.getUrls(url)) {
                if(!vis.count(near) and getHost(near) == host) {
                    vis.insert(near);
                    q.push(near);
                    res.push_back(near);
                }
            }
        }
        return res;
    }
};