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
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        
        for(int i=0; i<n-1; i++){
            if(nums[i]>=nums[i+1]){
                idx =i;
            }
            else 
                continue;
        }
        return (idx==-1) ? 0 : idx+1;
    }
};

int main(){

    return 0;
}