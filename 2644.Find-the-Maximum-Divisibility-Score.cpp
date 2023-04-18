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
    int maxDivScore(vector<int>& nums, vector<int>& div) {
        int n = nums.size();
        int m = div.size();
        int mx = -1;
        int ans =0;
        for(int i=0;i<m; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(nums[j]%div[i] == 0)
                    cnt++;
            }
            if(cnt >= mx){
                if(cnt == mx)
                    ans = min(ans,div[i]);
                else 
                    ans = div[i];
                mx= cnt;
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}