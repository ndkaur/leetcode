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
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        vector<int> ans(n,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i],i});
        }
        while(k--){
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            val = val*multiplier;
            pq.push({val, idx});
        }

        while(pq.size()){
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            ans[idx]= val;
        }
        return ans;
    }
};

int main(){

    return 0;
}