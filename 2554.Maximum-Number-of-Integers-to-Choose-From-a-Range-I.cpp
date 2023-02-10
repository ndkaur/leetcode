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
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> s;
        for(auto num:banned){
            s.insert(num);
        }
        int sum =0;
        int cnt =0;
        for(int i=1; i<=n; i++){
            if(s.find(i) == s.end() && sum+i <= maxSum){ // not found in set
                sum += i;
                cnt++;
            }
        }
        return cnt;
    }
};


int main(){

    return 0;
}

