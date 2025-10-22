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
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpeven, mpodd;
        int mx  =0;
        for(int i=0; i<n-1; i++){
            if(nums[i]%2==0)
                mpeven[nums[i]]++;
            else 
                mpodd[nums[i]]++;
            for(int j=i+1; j<n; j++){
                if(nums[j]%2==0)
                    mpeven[nums[j]]++;
                else 
                    mpodd[nums[j]]++;
                if(mpeven.size()==mpodd.size())
                    mx = max(mx, j-i+1);
            }
            mpeven.clear();
            mpodd.clear();
        }
        return mx;
    }
};



int main(){

    return 0;
}