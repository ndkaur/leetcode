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
    int largestCombination(vector<int>& can) {
        int n = can.size();
        int mx = 0;
        // if nums have same set bit at same index then definately the bitwise and will be greater than 1
        for(int i=0; i<32; i++){
            int cnt = 0;
            for(int num:can){
                if(num & (1<<i)){
                    cnt++;
                }
            }
            mx = max(mx, cnt);
        }
        return mx;
    }
};

int main(){

    return 0;
}