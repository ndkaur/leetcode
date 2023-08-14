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


class Solution0 {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        int mn = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=i+x; j<n; j++){
                if(abs(i-j)>=x){
                    int diff = abs(nums[j]-nums[i]);
                    mn = min(mn, diff);
                }
            }
        }
        return mn;
    }
};

//O(logn)
class Solution  {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        int mn = INT_MAX;
        set<int> st;
        for(int i=x; i<n; i++){ // idx>=x
        // optimal idx for i will be x positions back from i
            st.insert(nums[i-x]); // here idx condition is satisfied
            // we have to find the val >= num[i] in set so to get min diff
            // set will contain all the values possible for the current idx
            // and finding the immidiate greater or equal can give min diff 
            auto itr =  st.lower_bound(nums[i]);
            // if lb not found in set so the idx will be n -> out of set 
            if(itr!=st.end()){
                mn = min(mn, abs(nums[i]-*(itr)));
            }
            if(itr!=st.begin()){ // can be the end reduce itr to get it int he set indexes
                itr--;
                mn = min(mn, abs(nums[i]-*(itr)));
            }
        }
        return mn;
    }
};

int main(){

    return 0;
}