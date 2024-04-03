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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        int n = f.size();
        int m = s.size();
        vector<vector<int>> ans;
        int i = 0; 
        int j = 0;
        while(i<n && j<m){
            int low = max(f[i][0], s[j][0]);
            int high = min(f[i][1], s[j][1]);
            if(low<=high)
                ans.push_back({low, high});
            if(f[i][1]<s[j][1])
                i++;
            else 
                j++;
        }
        return ans;
    }
};

int main(){

    return 0;
}