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
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        int cnt= 0;
        map<int,int> mp;
        int l = 0;
        int r = 0;
        
        while(r<n){
            mp[arrivals[r]]++;
            while(mp[arrivals[r]]>m){
                cnt++;
                mp[arrivals[r]]--;
                arrivals[r]=0;
            }

            if((r-l+1)==w){
                mp[arrivals[l]]--;
                l++;
            }

            r++;
        }
        return cnt;
    }
};



int main(){

    return 0;
}