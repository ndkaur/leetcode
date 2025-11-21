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

// O(N)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        
        int ans = original;
        while(mp[original]){
            ans = ans*2;
            original = ans;
        }
        return ans;
    }
};


int main(){

    return 0;
}