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
    int reverse(int num){
        int val = 0;
        while(num){
            int rem = num%10;
            val = val*10+rem;
            num = num/10;
        }
        return val;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            if(mp.count(nums[i])){
                ans = min(ans, i-mp[nums[i]]);
            }

            int rev = reverse(nums[i]);
            mp[rev] = i;
        }
        return ans==INT_MAX ? -1 :ans;
    }
};




int main(){

    return 0;
}