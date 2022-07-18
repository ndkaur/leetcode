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
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums)
            mp[i]++;
        int operation=0;
        int cntOfNumLeft=0;
        vector<int> ans;
        for(auto itr:mp){
            operation+= itr.second%2;
            cntOfNumLeft+= itr.second/2;
        }
        return {operation, cntOfNumLeft};
    }
};

int main(){

    return 0;
}