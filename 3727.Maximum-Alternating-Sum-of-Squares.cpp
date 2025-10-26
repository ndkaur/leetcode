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
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<0)
                nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end());
        int l = 0;
        int r = n-1;
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            if(i%2==0){// even 
                ans += nums[r]*nums[r];
                r--;
            }
            else {
                ans -= nums[l]*nums[l];
                l++;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}