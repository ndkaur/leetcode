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
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,long long> mp;
        // find the xor of elements and store them in map
        long long ans =0;
        // cnt the times the same xor occur 
        int val =0;
        mp[val] =1;
        for(auto num:nums){
            val = val^num;
            mp[val]++;
        }
        // two nums choose subtract the 2^k from them 
        // any number whose zor comes two times wll add 1 to ans
        for(auto m:mp){
            ans += ((m.second-1) * m.second)/2;
        }
        return ans;
    }
};
// nums = 4,3,1,2,4
// map
// 0 4 7 6
// 2 2 1 1 
//  ans = (2-1)*2 = 2/2 =1 
// ans = 1
// ans = (2-1)*2 = 2/2 = 1 
// ans = 1+1 = 2
// ans = (1-1)*1 = 0
// ans = 2


int main(){

    return 0;
}