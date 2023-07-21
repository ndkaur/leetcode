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
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        // n[i] - k <= n[i] <= n[i] + k 
        // n[i] - n[i] <= k+k 
        // n[i]-n[i] <= 2*k
        // n[j] - n[i] <=2k // valid case for sliding window 
        // n[j] - n[i] > 2k // invalid case so increment window size
        sort(nums.begin(), nums.end());
        // sliding window 
        int i =0;
        int j=0;
        int mx =0;
        while(j<n){
            if(nums[j]-nums[i] > 2*k)
                i++;
            else 
                mx = max(mx, j-i+1);
            j++;
        }
        return mx;
    }
};

int main(){

    return 0;
}