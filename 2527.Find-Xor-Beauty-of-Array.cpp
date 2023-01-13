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


// tle 
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    int val = ((nums[i] | nums[j]) & nums[k]);
                    ans =  ans ^ val;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(auto num:nums){
            ans = ans ^ num;
        }
        return ans;
    }
};

int main(){

    return 0;
}