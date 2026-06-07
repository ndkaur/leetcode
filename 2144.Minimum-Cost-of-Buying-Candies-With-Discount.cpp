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
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int ans = 0;
        int cnt =0;
        for(int i=n-1; i>=0; i--){
            if(cnt<2){
                ans += cost[i];
                cnt++;
            }
            else{
                cnt=0;
            }
        }
        return ans;
    }
};


int main(){

    return 0;
}