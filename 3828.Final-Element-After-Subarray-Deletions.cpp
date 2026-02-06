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
    int finalElement(vector<int>& nums) {
        int n = nums.size();
        // alice acan remove one elm or a subraay 
        // but the removal must be continous, alice want max score 
        // but in the end one elem must remin whch will be the ans 
        if(n==1)
            return nums[0];
        // 11,4,5 remove 4,5 and 11 reamins
        return max(nums[0], nums[n-1]);
    }
};



int main(){

    return 0;
}