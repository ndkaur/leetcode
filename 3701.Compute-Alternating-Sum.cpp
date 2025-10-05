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
    int alternatingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        for(int i=1; i<n; i++){
            if(i%2==0)
                ans+= nums[i];
            else 
                ans+= (-nums[i]);
        }
        return ans;
    }
};



int main(){

    return 0;
}