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
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        int cnt = 0;
        for(auto itr:mp){
            cnt += itr.second/2;
        }
        return (cnt==n/2);
    }
};


int main(){

    return 0;
}