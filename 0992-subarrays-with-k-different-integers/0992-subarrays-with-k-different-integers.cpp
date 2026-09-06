class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int k) {
      int res = 0, l = 0, r = 0, n = A.size();
    unordered_map<int,int> freq, lastSeen;
    multiset<int> lastSeens;
    auto add = [&](int idx) {
      freq[A[idx]]++;
      if(lastSeen.count(A[idx])) {
        auto it = lastSeens.find(lastSeen[A[idx]]);
        lastSeens.erase(it);
      }
      lastSeen[A[idx]] = idx;
      lastSeens.insert(idx);
    };
    auto del = [&](int idx) {
      if(--freq[A[idx]] == 0) {
        freq.erase(A[idx]);
        auto it = lastSeens.find(lastSeen[A[idx]]);
      lastSeens.erase(it);
      lastSeen.erase(A[idx]);
      }
      
    };
    while(r < n) {
      while(r < n and freq.size() <= k) {
        add(r++);
        if(freq.size() == k) {
          res += *begin(lastSeens) - l + 1;
        }
      }
      while(r < n and freq.size() > k) {
        del(l++);
        if(freq.size() == k) {
          res += *begin(lastSeens) - l + 1;
        }
      }
    }
    while(freq.size() > k) {
        del(l++);
        if(freq.size() == k) {
          res += *begin(lastSeens) - l + 1;
        }
      }
    return res;
    }
};