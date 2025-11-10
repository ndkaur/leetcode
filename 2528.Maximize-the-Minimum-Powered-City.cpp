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
    bool isPossible(long long pow, vector<int> stations, int range, int k){
        int n = stations.size();
        long long curr =0;
        long long needed = 0;
        // taking first window sum
        for(int i=0; i<=range; i++){
            curr += stations[i];
        }

        int l = 0;
        int r = range;
        for(int i=0; i<n; i++){
            // len is more from left side than required range , shift window
            if(i-l>range){
                curr -= stations[l];
                l++;
            }
            // if range is small from right side, add next sation 
            if(r-i<range && r<n-1){
                r++;
                curr += stations[r];
            }
            
            // when curr is less then mid , that means its a chance to increse power of the stations. but if we increase the left station when i=0; it will be of no use as the range will not be from both sides , so we increse the r side value 

            if(curr<pow){
                // how much we need to add 
                needed = pow-curr;
                if(k<needed)
                    return false;
                // by adding k we can find more max power 
                stations[r] += needed;
                // when the value of station is changed then the currpower will also change 
                curr += needed;
                k-=needed;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int range, int k) {
        int n = stations.size();
        long long l = 0;
        long long r = accumulate(stations.begin(), stations.end(), 0LL)+k;
        long long ans = 0;
        
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(isPossible(mid, stations, range, k)){
                ans = mid;
                // search for more large value 
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}