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
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int mxhz = 1;
        int mxvr = 1;

        // find consecutive bars in horizontal 
        int curr = 1;
        for(int i=1; i<hBars.size(); i++){
            if(hBars[i]-hBars[i-1]==1){
                curr++;
            }
            else 
                curr = 1;
            mxhz = max(mxhz, curr);
        }

        // finding the consecutive bars in vertical
        curr = 1;
        for(int i=1; i<vBars.size(); i++){
            if(vBars[i]-vBars[i-1]==1)
                curr++;
            else 
                curr =1;
            mxvr = max(mxvr, curr);
        }

        int side = min(mxhz, mxvr)+1;
        return side*side;
    }
};

// sort the array 
// find the longest consecutive in hbar and vbar 
// hbar -> height 
// v bar -> widht 



int main(){

    return 0;
}