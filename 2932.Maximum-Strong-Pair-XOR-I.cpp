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
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
       
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(abs(nums[j]-nums[i])<=min(nums[i],nums[j])){
                    mx = max(mx, nums[i]^nums[j]);
                }
            }
        }
       return mx;
    }
}; 

int main(){

    return 0;
}