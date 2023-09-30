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
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt =0;
        set<int> st;
        for(int i=n-1; i>=0; i--){
            if(st.size()==k){
                break;
            }
            else{
                if(nums[i]<=k){
                    st.insert(nums[i]);
                }
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){

    return 0;
}