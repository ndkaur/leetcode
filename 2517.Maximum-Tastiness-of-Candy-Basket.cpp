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
    bool isPossible(int mid, vector<int>& price, int k){
        int n = price.size();
        // we can only take k prices whose min abs should be max 
        int cnt = 1;
        int prev = price[0];
        for(int i=1; i<n; i++){
            if(price[i]-prev >= mid){ 
                cnt++;
                prev = price[i];
            }
        }

        if(cnt>=k)
            return true;
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        
        int l = 0;
        int r = price[n-1]-price[0];
        int ans = -1;

        while(l<=r){
            int mid = l+(r-l)/2;
            // taking mid as the min diff 
            if(isPossible(mid, price, k)){ 
                ans = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return ans;
    }
};



int main(){

    return 0;
}