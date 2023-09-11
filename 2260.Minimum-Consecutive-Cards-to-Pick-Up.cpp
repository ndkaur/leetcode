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

// sliding window 

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n= cards.size();
        map<int,int> mp;
        int i =0;
        int j =0;
        int mn =INT_MAX;
        
        while(j<n){
            mp[cards[j]]++;
            // invalid condition will be that 
            // our window has more elemts than in map
            // window size is more than the map size 
            // eg -> 3 4 2 3  window size = 4
            // mp[3,4,2] mp size() = 3
            while(mp.size() < j-i+1){
                mn = min(mn, j-i+1);
                mp[cards[i]]--;
                if(mp[cards[i]]==0)
                    mp.erase(cards[i]);
                i++;
            }
            j++;
        }
        return mn==INT_MAX ? -1 : mn;
    }
};

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