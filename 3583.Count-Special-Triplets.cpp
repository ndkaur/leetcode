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
    const int  mod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,int> left, right;
        // right map
        for(int i=1; i<n; i++){
            right[nums[i]]++;
        }
        // left map storing on the way
        // triplets cant go till end
        for(int i=0; i<n-1; i++){
            int freqLeft = left[nums[i]*2];
            int freqRight = right[nums[i]*2];

            cnt = (cnt+((long long)freqLeft*freqRight)%mod)%mod;
            
            left[nums[i]]++;
            right[nums[i+1]]--;
        }
        return cnt;
    }
};

// 0 1 2 3 4 
// 8 4 2 8 4

// brute force -> nested for loops, O(N^2)



int main(){

    return 0;
}