/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 */
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
// #include "LinkedList.h"

void print(vi &out){
for(auto x: out) cout<<x<<" ";
cout<<endl;
}

// @lc code=start
// think in way of valey and peak 
class Solution { // o(n)
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n= arr.size();
        if(n<2) return n;
        int mx=1; // if len is one then also 1 will be ans
        int start=0;
        int end = 0; 
        while(start+1<n){ // srt+1 because we compare two values start and start+1
            // if values equal
            if(arr[start] == arr[start+1]){ 
                start++;  // skip that index move forward
                continue;
            }
            end = start+1;
            while(end+1<n && check(arr,end)){
                end++;
            }
            // to find no btw start and end to count them 
            mx= max(mx,end-start+1); // count the no accured in between
            start=end; // starting where ended
        }
        return mx;
    }
    bool check(vector<int>& arr, int i){
        // check if valley or peek 
        return ((arr[i-1]<arr[i] && arr[i]>arr[i+1]) || (arr[i-1]>arr[i] && arr[i]<arr[i+1]));
    }
};
// @lc code=end


int main(){
    Solution sol;
    vector<int> arr={9,4,2,10,7,8,8,1,9};
    int ans = sol.maxTurbulenceSize(arr);
    cout<<ans;
   return 0;
}