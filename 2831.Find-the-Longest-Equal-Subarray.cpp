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

// we need to find the max freq of the cosecutive elemts after removing at maost k elems from inbetween 
class Solution0 { //O(2n)
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int  n= nums.size();
        map<int,int> mp;
        // same as 424. Longest Repeating Character Replacement
        // but here we need to find mx len not replace 
        int mx =0;
        int ans =0;
        int r =0;
        int l =0;
        while(r<n){
            mp[nums[r]]++;
            mx=  max(mx, mp[nums[r]]);
            // window len - max freq = to delte 
            // to delte <= k valid 
            if((r-l+1) - mx > k){ // not valid
                mp[nums[l]]--;
                l++;
            }
            ans = mx;
            r++;
        }
        return ans;
    }
};


class Solution { //O(n)
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int  n= nums.size();
        map<int,int> mp;
        // same as 424. Longest Repeating Character Replacement
        // but here we need to find mx len not replace 
        
        // we need to find max consecutive freq 
        int mx =0; 
        int len =0;
        
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            mx = max(mx, mp[nums[i]]);
            if(len-mx<k) { // valid
                len++;
            }
            else{
                mp[nums[i-len]]--;
            }
        }
        return mx;
    }
};
int main(){

    return 0;
}