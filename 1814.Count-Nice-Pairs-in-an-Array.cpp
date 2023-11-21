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
    int mod = 1e9+7;
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        // change condition -> nums[i] - rev[nums[i]]
        map<int,int> mp;
        int cnt =0;
        for(int i=0; i<n; i++){
            int r = reverse(nums[i]);
            int dif = nums[i]-r;
            mp[dif]++;
             // a pair is formed when it occures more than ones 
            cnt = (cnt+mp[dif]-1)%mod;
        }
        return cnt%mod;
    }
    int reverse(int num){
        int r=0;
        while(num){
            int rem = num%10;
            r = r*10 + rem;
            num = num/10;
        }
        return r;
    }
};

// 42 11 1 97
// (42-24) (11-11) (1-1) (97-79)
//  18       0       0     18

// 13 10 35 24 76
// (13-31) (10-1) (35-53) (24-42) (76-67)
//    18      9     18      18      9 

int main(){

    return 0;
}