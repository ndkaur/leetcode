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


class Solution0 { // tle 
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        set<int> st;
        
        vector<int> range;
        for (int i = -k; i <= k; i++) {
            range.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            bool inserted = false;
            // Try all shifts from -k to +k for *this element only*
            for (int j = 0; j < range.size(); j++) {
                int val = nums[i] + range[j];
                if (st.count(val) == 0) {
                    st.insert(val);
                    inserted = true;
                    break;
                }
            }
            if (!inserted) {
                // can't insert (all taken) — skip
            }
        }
        return st.size();
    }
};



class Solution { // tle 
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // so the range is {nums[i]-k, nums[i]+k}
        // we always take nums[i]-k but if that no is alreasy taken then we increase the range , that becomes nums[i]-k = prev+1
        int cnt =1;
        int prev = nums[0]-k;
        for(int i=1; i<n; i++){
            // nums in increasing order so the next num we take must be max 
            int val = max(nums[i]-k, prev+1);
            // maximum of the range is nums[i]+k, we can go out of bound to it
            if(val<=nums[i]+k){
                cnt++;
                prev = val;
            }
            else{
                prev = nums[i]+k; 
            }
        }
        return cnt;
    }
};



int main(){

    return 0;
}