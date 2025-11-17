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
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = -1;
        for(int i=0; i<n; i++){
            if(nums[i]==1 && prev>=0 && i-prev-1<k){
                return false;
                break;
            }
            if(nums[i]==1)
                prev = i;
        }
        return true;
    }
};

//4-0>k


int main(){

    return 0;
}