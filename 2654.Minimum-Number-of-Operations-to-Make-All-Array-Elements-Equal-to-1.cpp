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
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = count(nums.begin(), nums.end(),1); // even if a single 1 is found
        if(cnt)
            return (n-cnt);
        
        int ans =INT_MAX;

        for(int i=0; i<n; i++){
            int g= nums[i];
            for(int j=i+1; j<n; j++){
                g= __gcd(g, nums[j]);
                if(g==1){
                    ans = min(ans, j-i+(n-1));
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main(){

    return 0;
}