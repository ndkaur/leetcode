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
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            int lcm = nums[i];
            if(lcm == k) 
                cnt++;
            for(int j=i+1; j<n; j++){
                int gcd = __gcd(lcm, nums[j]);
                lcm = (lcm*nums[j]) / gcd;
                if(lcm > k)
                    break;
                if(lcm == k)
                    cnt++;
            }
        }
        return cnt;
    }
};


int main(){

    return 0;
}