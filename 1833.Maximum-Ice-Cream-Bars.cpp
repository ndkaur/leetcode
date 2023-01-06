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
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int ans =0;
        sort(costs.begin(), costs.end());
        // 1 1 2 3 4   val = 7
        for(int i=0; i<n; i++){
            if(costs[i] <= coins){
                ans++;
               coins =  coins - costs[i];
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}