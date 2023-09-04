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
    int countDistinct(vector<int>& nums, int k, int p) {
        int n= nums.size();
        int sum = 0;
        vector<int> pref(n+1);

        for(int i=0; i<n; i++){
            pref[i+1] = pref[i] + (nums[i]%p==0);
        }
        // prefix sum array is nums
        unordered_set<string> st;

        for(int i=0; i<n; i++){
            string temp ="";
            for(int j=i; j<n; j++){
                if(pref[j+1] - pref[i] <= k){
                    temp.push_back(nums[j]);
                    st.insert(temp);
                }
                else 
                    break;
            }
        }
        return st.size();
    }
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<string> s;
        int n= nums.size();
        for(int i=0;i<n;i++){
            int count=0;
            string str="";
            for(int j=i;j<n;j++){
                str+= nums[j] +'0'; //'0' mark the end of string
                if(nums[j]%p==0)
                    count++;
                if(count<=k)
                    s.insert(str);
                else break;
            }
        }
        return s.size();
    }
};

int main(){
    Solution sol;
    vector<int> nums={2,3,3,2,2};
    int k= 2;
    int p=2;
    int ans= sol.countDistinct(nums,k,p);
    cout<<ans;
    return 0;
}