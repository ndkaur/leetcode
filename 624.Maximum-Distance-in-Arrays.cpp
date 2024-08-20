#include "bits/stdc++.h"
using namespace std;
// #include "Tree.h"
#define deb(x) cout<<x<<endl;
const int inf = 1e9;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
//#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

// linear time complexity -> O(N)
// space complexity -> constant space we using 
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrs) {
        int n = arrs.size();
        int mn = arrs[0].front();
        int mx = arrs[0].back();
        int ans = INT_MIN;

        for(int i=1; i<n; i++){
            int diff1 = abs(arrs[i].back()-mn); // mx of new arr - mn
            int diff2 = abs(arrs[i].front()-mx); // mn of new arr - mx 
            ans = max({ans, diff1, diff2});

            mn = min(mn, arrs[i].front());
            mx = max(mx, arrs[i].back());
        }
        return ans;
    }
};


int main(){

    return 0;
}