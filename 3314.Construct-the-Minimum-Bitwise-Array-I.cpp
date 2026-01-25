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
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);

        for(int i=0; i<n; i++){
            int val = nums[i];
            
            for(int j=1; j<val; j++){
                if((j | (j+1))==val){
                    ans[i] = (j);
                    break;
                }
            }      
        }
        return ans;
    }
};


int main(){

    return 0;
}