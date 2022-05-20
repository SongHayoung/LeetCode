// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        int pos = 0, mi = INT_MIN, ma = INT_MAX;
        vector<pair<int,int>> st;
        st.push_back({mi, ma});
        while(!st.empty() and pos < N) {
            auto p = st.back(); st.pop_back();
            if(p.first < arr[pos] and arr[pos] < p.second) {
                st.push_back({arr[pos], p.second});
                st.push_back({p.first, arr[pos]});
                pos++;
            }
        }
        return pos >= N;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}  // } Driver Code Ends