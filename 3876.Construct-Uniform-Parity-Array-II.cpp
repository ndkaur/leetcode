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
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int even =0;
        int odd = 0;
        for(int i=0; i<n; i++){
            if(nums1[i]%2==0)
                even++;
            else 
                odd++;
        }

        if(even==n || odd==n)
            return true;
        // mix of even odd
        // eplace all even with min odd diff
        int mn = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums1[i]%2==1) // min from odd
                mn = min(mn, nums1[i]);
        }

        for(int i=0; i<n; i++){
            // repalce all evens
            if(nums1[i]%2==0 && nums1[i]-mn<1)
                return false;
        }
        return true;
    }
};


int main(){

    return 0;
}