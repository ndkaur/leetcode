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

class Solution0 {
public:
    int countKthRoots(int l, int r, int k) {
        int cnt = 0;
        for(int i=0; i<=r; i++){
            if(pow(i,k)>=l && pow(i,k)<=r){
                cnt++;
            }
            else if(pow(i,k)>r){
                break;
            }
        }
        return cnt;
    }
};

// binary search to find valid for val>=l and valid for val<=r , then cnt the total between r-l+1

class Solution { // log r
public:
    int findleft(int l, int k){
        int low = 0;
        int high = l;
        if(k==0)
            low++;
        int ans = -1;

        while(low<=high){
            int mid = low+(high-low)/2;
            double val = pow(mid*1.0, k);

            if(val>=l){ // find much lower then 
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

    int findright(int r, int k){
        int low =0;
        int high = r;
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            double val = pow(mid*1.0, k);

            if(val<=r){
                ans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return ans;
    }

    int countKthRoots(int l, int r, int k) {
        if(k==1)
            return (r-l+1);

        int left = findleft(l,k);
        int right = findright(r,k);
        
        return right-left+1;
    }
};


int main(){

    return 0;
}