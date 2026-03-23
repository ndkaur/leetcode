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
    void find(int i, int xorr, int cnt, vector<int>& arr, map<int,int>& mp){
        int n = arr.size();
        if(i==n){
            mp[xorr]= max(mp[xorr], cnt);
            return;
        }
        // notpick 
        find(i+1, xorr, cnt, arr, mp);
        // pick
        find(i+1, xorr^arr[i], cnt+1, arr, mp);
    }
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        int mid = n/2;
        vector<int> left(nums.begin(), nums.begin()+mid);
        vector<int> right(nums.begin()+mid, nums.end());
    
        map<int,int> mpleft, mpright;
        // i, xor, cnt
        find(0,0,0,left, mpleft);
        find(0,0,0, right, mpright);

        int ans = -1;

        for(auto& itr:mpleft){
            // a^b=target
            int val = itr.first;
            int cnt = itr.second;
            int req = val^target;

            if(mpright.count(req)){
                ans = max(ans, cnt+mpright[req]);
            }
        }
        if(ans==-1)
            return -1;
        return n-ans;
    }
};

// so simply ques means we want to find a subarray whose xor is equal to target , ans we wan the subarray size to be max, so that in the end we have to remove min elements

// so there can be many subarrays, we will didvide the arry in two halfs , check for subarray in each half, then store the availbe resulting xor in map

// rule of xor -> a^b =target
// a^target = b 
// we will find b in other map , if found then answer it is 



int main(){

    return 0;
}