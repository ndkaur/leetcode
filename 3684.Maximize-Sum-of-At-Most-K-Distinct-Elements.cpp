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
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        set<int> st(nums.begin(), nums.end());
        priority_queue<int> pq;
        for(auto itr:st){
            pq.push(itr);
        }
        while(pq.size() && k--){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};



int main(){

    return 0;
}