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
    int theMaximumAchievableX(int num, int t) {
        int ans = num + t;
        // t add twice if num cnt one step then for x also cnt 1 step 
        ans += t;
        return ans;
    }
};

int main(){

    return 0;
}