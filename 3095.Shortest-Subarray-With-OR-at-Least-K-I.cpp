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
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int mn = 1e9;
        for(int i=0; i<n; i++){
            int orr = 0;
            for(int j=i; j<n; j++){
                orr |= nums[j];
                if(orr>=k){
                    mn = min(mn, j-i+1);
                }
            }
        }
        if(mn==1e9)
            return -1;
        return mn;
    }
};


int main(){

    return 0;
}