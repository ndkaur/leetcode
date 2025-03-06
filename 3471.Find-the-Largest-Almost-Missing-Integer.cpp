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
        int largestInteger(vector<int>& nums, int k) {
            int n = nums.size();
            map<int,int> mp;
            // num must apper exactly one in a subarray 
            // but in that subarray it can exist many times it will not be a issue 
            for(int i=0; i<=n-k; i++){
                set<int> st;
                for(int j=i; j<i+k; j++){
                    if(st.find(nums[j])==st.end()) // not found
                        mp[nums[j]]++;
                    st.insert(nums[j]);
                }
            }
            int mx = -1;
    
            for(auto itr:mp){
                if(itr.second==1){
                    mx = max(mx, itr.first);
                }
            }
            return mx;
        }
    };

int main(){

    return 0;
}