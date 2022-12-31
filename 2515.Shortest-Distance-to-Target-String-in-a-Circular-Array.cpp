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
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            if(words[i] ==  target){
                int directDis = abs(startIndex - i);
                int reverseDis = abs(n- directDis);
                int mnDis = min(directDis, reverseDis);
                ans = min(ans, mnDis);
            }
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};


int main(){

    return 0;
}