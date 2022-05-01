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

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n= cards.size();
        int ans =INT_MAX;
        unordered_map<int,vector<int>> mp; // no and its idx
        for(int i=0;i<n;i++)
            mp[cards[i]].push_back(i);
        for(auto & itr:mp){
            int sz= itr.second.size();
            for(int i=1;i<sz;i++){
                ans = min(ans,itr.second[i]-itr.second[i-1]+1);
            }
        }
        return (ans==INT_MAX) ? -1: ans;
    }
};

int main(){
    Solution sol;
    vector<int> cards={3,4,2,3,4,7};
    int ans= sol.minimumCardPickup(cards);
    cout<<ans;
    return 0;
}