#include "bits/stdc++.h"
using namespace std;
#include "Tree.h"
#define deb(x) cout<<x<<endl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int,int> pii;
#include "LinkedList.h"

void print(vi &out){
    for(auto x: out) cout<<x<<" ";
    cout<<endl;
}

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n=position.size();
        int even =0;
        int odd=0;
        for(int i:position){
            if(i%2==0) even++;
            else odd++;
        }
        return min(even,odd);
    }
};


int main(){
    Solution sol;
    vector<int> position={1,1000000000};
    int ans=sol.minCostToMoveChips(position);
    cout<<ans;
    return 0;
}