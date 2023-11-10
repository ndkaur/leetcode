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
    vector<int> restoreArray(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans;
        unordered_map<int,vector<int>> pairs;
        // making adjacent pairs
        for(auto a:adj){
            int u = a[0];
            int v = a[1];
            pairs[u].push_back(v);
            pairs[v].push_back(u);
        }

        // finding the number with only one adj that will be start 
        for(auto p:pairs){
            if(p.second.size()==1){
                ans.push_back(p.first);
                ans.push_back(p.second[0]);
                break;
            }
        }
        // adding rest of values
        while(ans.size() < n+1){
            auto tail = ans.back();
            auto prev = ans[ans.size()-2];
            auto next = pairs[tail];

            if(next[0]!=prev)
                ans.push_back(next[0]);
            else 
                ans.push_back(next[1]);
        }
        return ans;
    }
};

// 1 -> 2
// 2 -> 1, 3
// 3 -> 4, 2
// 4 -> 3, 
//  ans -> 1 , 2 
//  tail = 2 , prev = 1, next = mp[2] = 1,3
// 1 already visited = prev so use 3 
//  ans = 1, 2, 3 
//  tail = 3 , prev = 2 , mp[3] = 4,2 
// ans = 1,2,3,4


int main(){

    return 0;
}