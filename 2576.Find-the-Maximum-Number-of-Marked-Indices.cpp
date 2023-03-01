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
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int  n= nums.size();
        sort(nums.begin(), nums.end());
        int l =0;
        int r = n/2;
        while(l<n/2 && r<n){
            if(nums[l]*2 <= nums[r])
                l++;
            r++;
        }
        return l*2;
    }
};

int main(){

    return 0;
}